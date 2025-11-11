// ----------------------
// PIN DEFINITIONS
// ----------------------

// Segment pins for the 7-segment display (common anode type)
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;  // Decimal point

// Digit control pins for 4-digit multiplexed display (common cathodes)
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

// ----------------------
// GLOBAL VARIABLES
// ----------------------

long n = 1230;  // Example number to display
int daysYear = 365;
int daysLeft = 45;
int secondsInDay = 86400;

// ----------------------
// SETUP FUNCTION
// ----------------------
void setup() {
  // Set all digit control pins as outputs
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  // Set all segment pins as outputs
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

// ----------------------
// MAIN LOOP
// ----------------------
void loop() {
  // Display each digit with its corresponding number
  // For testing: digit 1 shows "1", digit 2 shows "2", etc.
  Display(1, 0);
  Display(2, 2);
  Display(3, 3);
  Display(4, 4);
}

// ----------------------
// DIGIT SELECTION FUNCTION
// ----------------------
// Turns ON only one of the 4 digits at a time
void position(unsigned char n) {
  switch (n) {
    case 1:                    // Activate first digit
      digitalWrite(d1, LOW);   // LOW = ON for common cathode
      digitalWrite(d2, HIGH);  // Turn OFF others
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
      break;

    case 2:  // Activate second digit
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
      break;

    case 3:  // Activate third digit
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH);
      break;

    case 4:  // Activate fourth digit
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW);
      break;

    default:  // Turn off all digits
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
      break;
  }
}

// ----------------------
// NUMBER DISPLAY FUNCTIONS (0–9)
// ----------------------
// Each function lights up the correct segments for that number
// HIGH = ON for common anode display (if common cathode, it would be LOW)

void Num_0() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);   // middle segment off
  digitalWrite(dp, LOW);  // decimal point off
}

void Num_1() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

void Num_2() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_3() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_4() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_5() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_6() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_7() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

void Num_8() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

void Num_9() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp, LOW);
}

// ----------------------
// CLEAR DISPLAY FUNCTION
// ----------------------
// Turns all segments OFF
void Clear() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

// ----------------------
// PICK NUMBER FUNCTION
// ----------------------
// Calls the correct digit pattern function based on the input number
void pickNumber(unsigned char n) {
  switch (n) {
    case 0: Num_0(); break;
    case 1: Num_1(); break;
    case 2: Num_2(); break;
    case 3: Num_3(); break;
    case 4: Num_4(); break;
    case 5: Num_5(); break;
    case 6: Num_6(); break;
    case 7: Num_7(); break;
    case 8: Num_8(); break;
    case 9: Num_9(); break;
    default: Clear(); break;  // Invalid number → clear display
  }
}

// ----------------------
// DISPLAY FUNCTION
// ----------------------
// Controls which digit to show and what number to display
// x = digit position (1 to 4)
// Number = digit to show (0 to 9)
void Display(unsigned char x, unsigned char Number) {
  position(x);         // Select the digit
  pickNumber(Number);  // Display the number on that digit
  // show dot after third digit
  if (x == 3) digitalWrite(dp, HIGH);
  else digitalWrite(dp, LOW);
  delay(1);  // Short delay for persistence of vision
  Clear();   // Turn off all segments before next digit
}
