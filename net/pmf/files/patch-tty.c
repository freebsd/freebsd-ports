--- tty.c	Fri Oct 29 10:09:06 1993
+++ tty.c	Mon Mar 26 20:02:26 2007
@@ -18,6 +18,9 @@
 /* Added by dodurham@stimpy.ualr.edu for Linux machines */
 #ifdef SYSV
 #    include <termio.h>
+#elif defined(__FreeBSD__)
+#    include <termios.h>
+#    define termio termios
 #else
 #    include <sgtty.h>
 #endif
@@ -161,13 +164,13 @@
 
 pmf_save_terminal()
 {
-    if (ioctl(0, TCGETA, &terminal_state) == -1)
+    if (tcgetattr(0, &terminal_state) == -1)
 	fatal("ioctl TCGETA failed in pmf_save_terminal.");
 } /* pmf_save_terminal */
 
 pmf_restore_terminal()
 {
-    if (ioctl(0, TCSETA, &terminal_state) == -1)
+    if (tcsetattr(0, TCSANOW, &terminal_state) == -1)
 	fatal("ioctl TCSETA failed in pmf_restore_terminal.");
 } /* pmf_restore_terminal */
 
