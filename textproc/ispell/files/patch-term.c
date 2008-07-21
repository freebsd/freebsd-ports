--- term.c.orig	2008-07-04 11:42:14.000000000 -0500
+++ term.c	2008-07-04 11:55:44.000000000 -0500
@@ -86,8 +86,12 @@
 #include "ispell.h"
 #include "proto.h"
 #include "msgs.h"
+#ifdef BSD_4_4
+#define USG
+#endif
 #ifdef USG
-#include <termio.h>
+#include <unistd.h>
+#include <termios.h>
 #else
 #ifndef __DJGPP__
 #include <sgtty.h>
@@ -166,8 +170,8 @@
     }
 
 #ifdef USG
-static struct termio	sbuf;
-static struct termio	osbuf;
+static struct termios	sbuf;
+static struct termios	osbuf;
 #else
 static struct sgttyb	sbuf;
 static struct sgttyb	osbuf;
@@ -276,7 +280,7 @@
 	(void) fprintf (stderr, TERM_C_NO_BATCH);
 	exit (1);
 	}
-    (void) ioctl (0, TCGETA, (char *) &osbuf);
+    tcgetattr(STDIN_FILENO, &osbuf);
     termchanged = 1;
 
     sbuf = osbuf;
@@ -285,7 +289,7 @@
     sbuf.c_iflag &= ~(INLCR | IGNCR | ICRNL);
     sbuf.c_cc[VMIN] = 1;
     sbuf.c_cc[VTIME] = 1;
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 
     uerasechar = osbuf.c_cc[VERASE];
     ukillchar = osbuf.c_cc[VKILL];
@@ -373,7 +377,7 @@
 	if (te)
 	    tputs (te, 1, iputch);
 #ifdef USG
-	(void) ioctl (0, TCSETAW, (char *) &osbuf);
+	tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
 	(void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -394,7 +398,7 @@
 	if (te)
 	    tputs (te, 1, iputch);
 #ifdef USG
-	(void) ioctl (0, TCSETAW, (char *) &osbuf);
+	tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
 	(void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -413,7 +417,7 @@
     if (termchanged)
 	{
 #ifdef USG
-	(void) ioctl (0, TCSETAW, (char *) &sbuf);
+	tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
 	(void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
@@ -481,7 +485,7 @@
     argv[i] = NULL;
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &osbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -527,7 +531,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
@@ -563,7 +567,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &osbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &osbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &osbuf);
 #ifdef TIOCSLTC
@@ -611,7 +615,7 @@
 #endif
 
 #ifdef USG
-    (void) ioctl (0, TCSETAW, (char *) &sbuf);
+    tcsetattr(STDIN_FILENO, TCSANOW, &sbuf);
 #else
     (void) ioctl (0, TIOCSETP, (char *) &sbuf);
 #ifdef TIOCSLTC
