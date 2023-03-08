// RISHI KAVI - N15231052 - rk4200
// RISHI ISHWAR VARMA - N17479594 - rv2210
// PENMETSA TEJASWI RAJU - N18266865 - pr2258
// AVIRAT VARMA - N17296397 - av3032
#include <mbed.h>
#define exh 150000000 //count value which will be checked for exhale
#define inh 200000000 // count value which will be checked for inhale, this is more than exhale because of the
                      // number of instructions between the checks of exhale and inhale
volatile int read_value=0;

int main(){
  int count_in=0; //counter for inhale time
  int count_ex=0; //counter for exhale time
  DigitalIn in1(PE_4,PullDown); // configuring pin4 on port E as a pull-down input pin
  DigitalOut led1(PE_2); // configuring pin2 on port E as an output pin
  led1.write(0); //initialising the led (or any indicator) to be off at first
  
  while((count_ex<exh) && (count_in<inh)) // check for count values that correspond to non-breathing for 10 seconds
  {
    if(in1.read()) //check if there is an input
    {
      count_ex=0; // if input is there -> person is inhaling so exhale is set to 0
      count_in++; // increment inhale counter to check for pre-defined inhale time threshold
    }
    else
    {
      count_in=0; // if input is there -> person is exhaling so inhale is set to 0
      count_ex++; // increment exhale counter to check for pre-defined inhale time threshold
    }
  }
  led1.write(1); //the 'while' condition will break and switch on led when the person stops inhaling or exhaling
                // that is - the person is not breathing properly
}