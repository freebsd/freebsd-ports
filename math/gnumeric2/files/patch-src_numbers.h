--- src/numbers.h.orig	Fri Dec 10 21:36:23 2004
+++ src/numbers.h	Fri Dec 10 21:37:02 2004
@@ -3,6 +3,7 @@
 
 #include <math.h>
 #ifdef HAVE_IEEEFP_H
+#include <sys/types.h>
 #include <ieeefp.h>
 #endif
 #ifdef HAVE_IEEE754_H
