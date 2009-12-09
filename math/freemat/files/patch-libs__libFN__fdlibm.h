--- ./libs/libFN/fdlibm.h.orig	2009-11-14 19:26:54.000000000 -0500
+++ ./libs/libFN/fdlibm.h	2009-11-14 19:27:53.000000000 -0500
@@ -11,13 +11,11 @@
  */
 
 /* REDHAT LOCAL: Include files.  */
+#include <stdarg.h>
 #include <math.h>
 //#include <sys/types.h>
 //#include <machine/ieeefp.h>
 
-typedef  __int32 __int32_t;
-typedef  unsigned __int32 __uint32_t;
-
 #define __IEEE_LITTLE_ENDIAN
 
 /* REDHAT LOCAL: Default to XOPEN_MODE.  */
