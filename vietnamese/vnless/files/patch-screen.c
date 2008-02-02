--- screen.c.orig	Mon Feb 24 12:45:41 1992
+++ screen.c	Sat Feb  2 11:10:28 2008
@@ -12,7 +12,11 @@
 #endif
 
 #if TERMIO
+# ifdef BSD4_4
+#include <sys/termios.h>
+# else
 #include <termio.h>
+# endif
 #else
 #include <sgtty.h>
 #endif
@@ -92,21 +96,35 @@ raw_mode(on)
 	int on;
 {
 #if TERMIO
+#ifdef BSD4_4
+	struct termios s;
+	static struct termios save_term;
+#else
 	struct termio s;
 	static struct termio save_term;
+#endif
 
 	if (on)
 	{
 		/*
 		 * Get terminal modes.
 		 */
+#ifdef BSD4_4
+		tcgetattr(2, &s);
+#else
 		ioctl(2, TCGETA, &s);
+#endif
 
 		/*
 		 * Save modes and set certain variables dependent on modes.
 		 */
 		save_term = s;
-		ospeed = s.c_cflag & CBAUD;
+		ospeed =
+#ifdef BSD4_4
+			cfgetospeed(&s);
+#else
+			s.c_cflag & CBAUD;
+#endif
 		erase_char = s.c_cc[VERASE];
 		kill_char = s.c_cc[VKILL];
 
@@ -114,7 +132,12 @@ raw_mode(on)
 		 * Set the modes to the way we want them.
 		 */
 		s.c_lflag &= ~(ICANON|ECHO|ECHOE|ECHOK|ECHONL);
-		s.c_oflag |=  (OPOST|ONLCR|TAB3);
+		s.c_oflag |=
+#ifdef BSD4_4
+			      (OPOST|ONLCR|OXTABS);
+#else
+			      (OPOST|ONLCR|TABS3);
+#endif
 		s.c_oflag &= ~(OCRNL|ONOCR|ONLRET);
 		s.c_cc[VMIN] = 1;
 		s.c_cc[VTIME] = 0;
@@ -125,7 +148,11 @@ raw_mode(on)
 		 */
 		s = save_term;
 	}
+# ifdef BSD4_4
+	tcsetattr(2, TCSANOW, &s);
+# else
 	ioctl(2, TCSETAW, &s);
+# endif
 #else
 	struct sgttyb s;
 	static struct sgttyb save_term;
@@ -480,7 +507,7 @@ vbell()
  * Clear the screen.
  */
 	public void
-clear()
+clearscr()
 {
 	tputs(sc_clear, sc_height, putchr);
 }
