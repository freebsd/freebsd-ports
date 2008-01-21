--- echo.c	1999-03-04 19:23:42.000000000 +0100
+++ echo.c	2007-12-28 15:23:31.000000000 +0100
@@ -18,12 +18,8 @@
 #include <sys/ioctl.h>
 #endif
 
-#if defined(HAVE_SYS_TERMIO_H) && !defined(BSD_ECHO) || defined(HAVE_TERMIO_H)
-#if defined(HAVE_SYS_TERMIO_H)
-#include <sys/termio.h>
-#else
-#include <termio.h>
-#endif
+#if 1
+#include <termios.h>
 #else
 #include <sgtty.h>
 #if DIRTY_REDEFINE
@@ -34,8 +30,8 @@
 #endif
 #endif
 
-#if defined(HAVE_SYS_TERMIO_H) && !defined(BSD_ECHO) || defined(HAVE_TERMIO_H)
-#ifdef HAVE_TCFLAG_T
+#if 1
+#if 1
 extern tcflag_t c_lflag;
 extern cc_t c_cc[NCCS];
 #else
@@ -44,10 +40,10 @@
 #endif
 void init_echo()
 {
-  struct  termio io;
+  struct  termios io;
 
-  if(ioctl(0, TCGETA, &io)<0)
-    syserr("ioctl");
+  if(tcgetattr(0, &io)<0)
+    syserr("tcgetattr");
   c_lflag = io.c_lflag;
   c_cc[VMIN] = io.c_cc[VMIN];
   c_cc[VTIME] = io.c_cc[VTIME];
@@ -58,14 +54,14 @@
 /********************************/
 void term_echo()
 {
-  struct  termio io;
+  struct  termios io;
 
-  if(ioctl(0, TCGETA, &io)<0)
+  if(tcgetattr(0, &io)<0)
     syserr("ioctl");
   io.c_lflag = c_lflag;
   io.c_cc[VMIN] = c_cc[VMIN];
   io.c_cc[VTIME] = c_cc[VTIME];
-  if(ioctl(0, TCSETA, &io)<0)
+  if(tcsetattr(0, TCSANOW, &io)<0)
     syserr("ioctl");
 }
 
@@ -74,15 +70,15 @@
 /*********************************/
 void term_noecho()
 {
-  struct  termio io;
+  struct  termios io;
 
-  if(ioctl(0, TCGETA, &io)<0)
+  if(tcgetattr(0, &io)<0)
     syserr("ioctl");
   io.c_lflag &= ~ECHO; 
   io.c_lflag &= ~ICANON;
   io.c_cc[VMIN]=1;
   io.c_cc[VTIME]=0;
-  if(ioctl(0, TCSETA, &io) < 0)
+  if(tcsetattr(0, TCSANOW, &io) < 0)
     syserr("ioctl");
 }
 
