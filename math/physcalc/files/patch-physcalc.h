--- physcalc.h	Sun Aug 27 17:46:31 2000
+++ physcalc.h.new	Sun Aug 27 17:46:57 2000
@@ -22,6 +22,10 @@
 #error This program requires more memory than the tiny model allows!
 #endif
 
+#ifndef SHAREDIR
+#define SHAREDIR "/usr/share/physcalc/"
+#endif
+
 #define VERSION "2.4"       /* Version number */
 #define TRACE
 
