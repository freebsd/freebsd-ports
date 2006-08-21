--- iaxmodem.c.orig	Mon Jul 31 15:29:29 2006
+++ iaxmodem.c	Fri Aug 11 20:23:50 2006
@@ -17,12 +17,14 @@
  */
 #include <stdio.h>
 #include <string.h>
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <pty.h>
 #else
 #include <termios.h>
+#if !defined(__FreeBSD__)
 #include <util.h>
 #endif
+#endif
 #include <stdlib.h>
 #include <unistd.h>
 #include <dirent.h>
@@ -44,6 +46,10 @@
 #include <math.h>
 
 #include <stdint.h>
+
+#ifdef __FreeBSD__
+#include <libutil.h>
+#endif
 #include <tiffio.h>
 
 #include <spandsp.h>
