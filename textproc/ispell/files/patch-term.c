--- term.c	Wed Jul 25 23:51:46 2001
+++ term.c	Fri Mar 16 10:52:35 2007
@@ -80,8 +80,10 @@
 #include "ispell.h"
 #include "proto.h"
 #include "msgs.h"
+#define USG
 #ifdef USG
-#include <termio.h>
+#include <unistd.h>
+#include <termios.h>
 #else
 #include <sgtty.h>
 #endif
@@ -152,8 +154,8 @@
     }
 
 #ifdef USG
-static struct termio	sbuf;
-static struct termio	osbuf;
+static struct termios	sbuf;
+static struct termios	osbuf;
 #else
 static struct sgttyb	sbuf;
 static struct sgttyb	osbuf;
@@ -263,7 +265,7 @@
 	(void) fprintf (stderr, TERM_C_NO_BATCH);
 	exit (1);
 	}
-    (void) ioctl (0, TCGETA, (char *) &osbuf);
+    tcgetattr(STDIN_FILENO, &osbuf);
     termchanged = 1;
 
     sbuf = osbuf;
@@ -272,7 +274,7 @@
     sbuf.c_iflag &= ~(INLCR | IGNCR | ICRNL);
     sbuf.c_cc[VMIN] = 1;
     sbuf.c_cc[VTIME] = 1;
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 
     uerasechar = osbuf.c_cc[VERASE];
     ukillchar = osbuf.c_cc[VKILL];
@@ -360,7 +362,7 @@
 	if (te)
 	    tputs (te, 1, putch);
 #ifdef USG
-	(void) ioctl (0, TCSETAW, (char *) &osbuf);
+	tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
 	(void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -376,7 +378,7 @@
     int		signo;
     {
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &osbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -391,7 +393,7 @@
     /* stop here until continued */
     (void) signal (signo, onstop);
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
@@ -451,7 +453,7 @@
     argv[i] = NULL;
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &osbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -497,7 +499,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
@@ -530,7 +532,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &osbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -562,7 +564,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
