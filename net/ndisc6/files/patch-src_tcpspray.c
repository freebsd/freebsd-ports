--- src/tcpspray.c.orig	Wed Jul 12 19:01:50 2006
+++ src/tcpspray.c	Sat Aug  5 16:31:01 2006
@@ -48,6 +48,10 @@
 # include <getopt.h>
 #endif
 
+#ifndef SIZE_MAX
+#  define SIZE_MAX SIZE_T_MAX
+#endif
+
 static int family = 0;
 static unsigned verbose = 0;
 
