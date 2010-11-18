
$FreeBSD$

--- config.h.orig
+++ config.h
@@ -13,13 +13,13 @@
 /* SERIAL_CONSOLE_DEFAULT -  The default state of the serial console. */
 /*	This is normally off since it slows down testing.  Change to a 1 */
 /*	to enable. */
-#define SERIAL_CONSOLE_DEFAULT 0
+#define SERIAL_CONSOLE_DEFAULT 1
 
 /* SERIAL_TTY - The default serial port to use. 0=ttyS0, 1=ttyS1 */ 
 #define SERIAL_TTY 0
 
 /* SERIAL_BAUD_RATE - Baud rate for the serial console */
-#define SERIAL_BAUD_RATE 9600
+#define SERIAL_BAUD_RATE 115200
 
 /* BEEP_MODE - Beep on error. Default off, Change to 1 to enable */
 #define BEEP_MODE 0
