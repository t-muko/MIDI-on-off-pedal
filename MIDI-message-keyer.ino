
/* 
 DESCRIPTION
 ====================
 Two independent channels.
 Toggle the state of the channel when a button is pressed.
 Send a MIDI message when turning the state on or off.
 */
 
// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h> // Use bounce2 library for key debounce

#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3

#define LED_PIN1 12
#define LED_PIN2 13

#define DEBOUNCE_INTERVAL 20 // Define debounce time in ms

// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 

// Instantiate another Bounce object
Bounce debouncer2 = Bounce(); 

// Store channel enable states
boolean Ch1Enabled = true; // Store enable status for ch1
boolean Ch2Enabled = true; // Store enable status for ch2


void setup() {
  // put your setup code here, to run once:

  // Setup the first button with an internal pull-up :
  pinMode(BUTTON_PIN_1,INPUT_PULLUP);
  
  // After setting up the button, setup the Bounce instance :
  debouncer1.attach(BUTTON_PIN_1);
  debouncer1.interval(DEBOUNCE_INTERVAL); // interval in ms
  
   // Setup the second button with an internal pull-up :
  pinMode(BUTTON_PIN_2,INPUT_PULLUP);
  
  // After setting up the button, setup the Bounce instance :
  debouncer2.attach(BUTTON_PIN_2);
  debouncer2.interval(DEBOUNCE_INTERVAL); // interval in ms


  //Setup LEDs :
  pinMode(LED_PIN1,OUTPUT);
  pinMode(LED_PIN2,OUTPUT);

  // testing LEDs
  digitalWrite(LED_PIN1, HIGH ); 
  digitalWrite(LED_PIN2, HIGH ); 
  delay(500);
  digitalWrite(LED_PIN1, LOW ); 
  digitalWrite(LED_PIN2, LOW ); 
  delay(500);
  digitalWrite(LED_PIN1, HIGH ); 
  digitalWrite(LED_PIN2, HIGH ); 

}

void loop() {
  // put your main code here, to run repeatedly:
  // Update the Bounce instances :
  debouncer1.update();

  // Get the updated value :
//  int toggleCh1 = debouncer1.read();
//  int toggleCh2 = debouncer2.read();

  // Turn on the LED if the button is pressed :
  if ( debouncer1.fell() ) {
    switch (Ch1Enabled) {
    case false:
      // Turn Ch1 on
      Ch1Enabled = true;
      digitalWrite(LED_PIN1, HIGH );
      break;
         
    case true:
      // Turn Ch2 off
      Ch1Enabled = false;
      digitalWrite(LED_PIN1, LOW );
      break;
    }
  }
  

  debouncer2.update();

  // Turn on the LED if the button is pressed :
  if ( debouncer2.fell() ) {
    switch (Ch2Enabled) {
    case false:
      // Turn Ch2 on
      Ch2Enabled = true;
      digitalWrite(LED_PIN2, HIGH );
      break;
         
    case true:
      // Turn Ch2 off
      Ch2Enabled = false;
      digitalWrite(LED_PIN2, LOW );
      break;
    }
  }


}
