--- numpy/core/include/numpy/ufuncobject.h.orig	2008-04-06 22:57:59.000000000 +0900
+++ numpy/core/include/numpy/ufuncobject.h	2008-04-06 23:02:05.000000000 +0900
@@ -267,7 +267,10 @@
 /* Solaris --------------------------------------------------------*/
 /* --------ignoring SunOS ieee_flags approach, someone else can
 **         deal with that! */
-#elif defined(sun) || defined(__BSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+#elif defined(sun) || defined(__BSD__) || defined(__OpenBSD__) || (defined(__FreeBSD__) && (__FreeBSD_version < 502114)) || defined(__NetBSD__)
 #include <ieeefp.h>
 
 #define UFUNC_CHECK_STATUS(ret) {				\
@@ -281,9 +284,9 @@
 	(void) fpsetsticky(0);						\
 	}
 
-#elif defined(__GLIBC__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__)
+#elif defined(__GLIBC__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 #include <fenv.h>
 #elif defined(__CYGWIN__)
 #include "fenv/fenv.c"
