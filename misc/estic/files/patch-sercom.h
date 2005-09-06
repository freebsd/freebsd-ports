--- spunk/sercom.h.orig	Thu Nov  7 18:06:52 1996
+++ spunk/sercom.h	Tue Sep  6 09:54:21 2005
@@ -43,29 +43,29 @@
 
 
 // Constants for accessing the array of error counters
-const ceRXOverflow              = 0;    // Receive buffer overflow
-const ceTXOverflow              = 1;    // Transmit buffer overflow
-const ceOverrun                 = 2;    // UART overrun
-const ceBreak                   = 3;    // Break received
-const ceFrame                   = 4;    // Framing error
-const ceParity                  = 5;    // Parity error
+const int ceRXOverflow              = 0;    // Receive buffer overflow
+const int ceTXOverflow              = 1;    // Transmit buffer overflow
+const int ceOverrun                 = 2;    // UART overrun
+const int ceBreak                   = 3;    // Break received
+const int ceFrame                   = 4;    // Framing error
+const int ceParity                  = 5;    // Parity error
 
 
 
 // Bitmask constants for evaluating the result of ModemStatus
-const csDeltaCTS                = 0x01; // Delta CTS
-const csDeltaDSR                = 0x02; // Delta DSR
-const csDeltaRI                 = 0x04; // Falling edge of RI
-const csDeltaCarrierDetect      = 0x08; // Delta CD
-const csClearToSend             = 0x10; // Clear To Send
-const csDataSetReady            = 0x20; // Data Set Ready
-const csRingIndicator           = 0x40; // Ring Indicator
-const csCarrierDetect           = 0x80; // Carrier Detect
-const csCTS                     = csClearToSend;
-const csDSR                     = csDataSetReady;
-const csRI                      = csRingIndicator;
-const csCD                      = csCarrierDetect;
-const csDeltaCD                 = csDeltaCarrierDetect;
+const int csDeltaCTS                = 0x01; // Delta CTS
+const int csDeltaDSR                = 0x02; // Delta DSR
+const int csDeltaRI                 = 0x04; // Falling edge of RI
+const int csDeltaCarrierDetect      = 0x08; // Delta CD
+const int csClearToSend             = 0x10; // Clear To Send
+const int csDataSetReady            = 0x20; // Data Set Ready
+const int csRingIndicator           = 0x40; // Ring Indicator
+const int csCarrierDetect           = 0x80; // Carrier Detect
+const int csCTS                     = csClearToSend;
+const int csDSR                     = csDataSetReady;
+const int csRI                      = csRingIndicator;
+const int csCD                      = csCarrierDetect;
+const int csDeltaCD                 = csDeltaCarrierDetect;
 
 
 
