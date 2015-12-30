--- src/hashcat-cli.c.orig	2015-12-04 15:35:08 UTC
+++ src/hashcat-cli.c
@@ -17,14 +17,14 @@
 
 // for interactive status prompt
 #ifdef POSIX
-#ifndef OSX
+#if defined(OSX) || defined(__FreeBSD__)
 
-#include <termio.h>
+#include <termios.h>
+#include <sys/ioctl.h>
 
 #else
 
-#include <termios.h>
-#include <sys/ioctl.h>
+#include <termio.h>
 
 #endif
 #endif
@@ -2836,16 +2836,16 @@ void save_hash ()
 
 #ifdef POSIX
 
-#ifndef OSX
+#if defined(OSX) || defined(__FreeBSD__)
 
-static struct termio savemodes;
+static struct termios savemodes;
 static int havemodes = 0;
 
 int tty_break ()
 {
-  struct termio modmodes;
+  struct termios modmodes;
 
-  if (ioctl (fileno (stdin), TCGETA, &savemodes) < 0) return -1;
+  if (ioctl (fileno (stdin), TIOCGETA, &savemodes) < 0) return -1;
 
   havemodes = 1;
 
@@ -2854,7 +2854,7 @@ int tty_break ()
   modmodes.c_cc[VMIN] = 1;
   modmodes.c_cc[VTIME] = 0;
 
-  return ioctl (fileno (stdin), TCSETAW, &modmodes);
+  return ioctl (fileno (stdin), TIOCSETAW, &modmodes);
 }
 
 int tty_getchar ()
@@ -2882,19 +2882,19 @@ int tty_fix ()
 {
   if (!havemodes) return 0;
 
-  return ioctl (fileno (stdin), TCSETAW, &savemodes);
+  return ioctl (fileno (stdin), TIOCSETAW, &savemodes);
 }
 
 #else
 
-static struct termios savemodes;
+static struct termio savemodes;
 static int havemodes = 0;
 
 int tty_break ()
 {
-  struct termios modmodes;
+  struct termio modmodes;
 
-  if (ioctl (fileno (stdin), TIOCGETA, &savemodes) < 0) return -1;
+  if (ioctl (fileno (stdin), TCGETA, &savemodes) < 0) return -1;
 
   havemodes = 1;
 
@@ -2903,7 +2903,7 @@ int tty_break ()
   modmodes.c_cc[VMIN] = 1;
   modmodes.c_cc[VTIME] = 0;
 
-  return ioctl (fileno (stdin), TIOCSETAW, &modmodes);
+  return ioctl (fileno (stdin), TCSETAW, &modmodes);
 }
 
 int tty_getchar ()
@@ -2931,8 +2931,9 @@ int tty_fix ()
 {
   if (!havemodes) return 0;
 
-  return ioctl (fileno (stdin), TIOCSETAW, &savemodes);
+  return ioctl (fileno (stdin), TCSETAW, &savemodes);
 }
+
 #endif
 #endif
 
