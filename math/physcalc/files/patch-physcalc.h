--- physcalc.h.orig	1998-08-29 14:13:40 UTC
+++ physcalc.h
@@ -22,6 +22,10 @@
 #error This program requires more memory than the tiny model allows!
 #endif
 
+#ifndef SHAREDIR
+#define SHAREDIR "/usr/share/physcalc/"
+#endif
+
 #define VERSION "2.4"       /* Version number */
 #define TRACE
 
