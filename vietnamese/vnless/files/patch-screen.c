--- screen.c.orig	Mon Feb 24 12:45:41 1992
+++ screen.c	Sat May 20 01:40:56 2000
@@ -12,7 +12,7 @@
 #endif
 
 #if TERMIO
-#include <termio.h>
+#include <termios.h>
 #else
 #include <sgtty.h>
 #endif
@@ -92,21 +92,21 @@
 	int on;
 {
 #if TERMIO
-	struct termio s;
-	static struct termio save_term;
+	struct termios s;
+	static struct termios save_term;
 
 	if (on)
 	{
 		/*
 		 * Get terminal modes.
 		 */
-		ioctl(2, TCGETA, &s);
+		tcgetattr(2, &s);
 
 		/*
 		 * Save modes and set certain variables dependent on modes.
 		 */
 		save_term = s;
-		ospeed = s.c_cflag & CBAUD;
+		ospeed = cfgetospeed(&s);
 		erase_char = s.c_cc[VERASE];
 		kill_char = s.c_cc[VKILL];
 
@@ -114,7 +114,7 @@
 		 * Set the modes to the way we want them.
 		 */
 		s.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHOK|ECHONL);
-		s.c_oflag |=  (OPOST|ONLCR|TAB3);
+		s.c_oflag |=  (OPOST|ONLCR|OXTABS);
 		s.c_oflag &= ~(OCRNL|ONOCR|ONLRET);
 		s.c_cc[VMIN] = 1;
 		s.c_cc[VTIME] = 0;
@@ -125,7 +125,7 @@
 		 */
 		s = save_term;
 	}
-	ioctl(2, TCSETAW, &s);
+	tcsetattr(2, TCSANOW, &s);
 #else
 	struct sgttyb s;
 	static struct sgttyb save_term;
@@ -480,7 +480,7 @@
  * Clear the screen.
  */
 	public void
-clear()
+clearscr()
 {
 	tputs(sc_clear, sc_height, putchr);
 }
