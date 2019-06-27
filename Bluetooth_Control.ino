/*
* Control LED's with Smartphone via bluetooth

*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(6,7); // RX, TX 

int led1 = 3;
int led2 = 4 ;

String state;

void setup() {
// sets the pins as outputs:
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);

// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
mySerial.begin(9600);
}

void loop() {
 while (mySerial.available()){  //Check if there is an available byte to read
 delay(10); //Delay added to make thing stable 
 char c = mySerial.read(); //Conduct a serial read
 //if (c == '#') {break;} //Exit the loop when the # is detected after the word
 state += c; //Shorthand for voice = voice + c
 Serial.println(state);
  } 

// if the state is 'LED1ON' the Led1 will turn on
if (state.equals("1")) {
digitalWrite(3, LOW);
Serial.println("Light On");
}
// if the state is 'LED1OFF' the led1 will turn off
else  if (state.equals("2")){
digitalWrite(3, HIGH); 
Serial.println("Light Off");
}
// if the state is 'LED2ON' the Led2 will turn on
else  if (state.equals("3")){
digitalWrite(4, LOW);
Serial.println("AC On");
} 

// if the state is 'LED2OFF' the led2 will turn off
else  if (state.equals("4")){
digitalWrite(4, HIGH);
Serial.println("AC Off");
}
// if the state is 'ALLON' the Led's will turn on
else if (state.equals("5")) {
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
Serial.println("All On");
}
// if the state is 'ALLOFF' the Led's will turn off
else if (state.equals("6")) {
digitalWrite(3, LOW);
digitalWrite(4, LOW);
Serial.println("All Off");
}


state="";
}
