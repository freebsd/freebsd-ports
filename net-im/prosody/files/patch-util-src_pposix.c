--- util-src/pposix.c.orig	2021-08-03 09:53:04 UTC
+++ util-src/pposix.c
@@ -30,9 +30,6 @@
 #define _DARWIN_C_SOURCE
 #endif
 #endif
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200809L
-#endif
 
 #include <stdlib.h>
 #include <math.h>
