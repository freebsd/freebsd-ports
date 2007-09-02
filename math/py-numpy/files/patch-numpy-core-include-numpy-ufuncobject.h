--- numpy/core/include/numpy/ufuncobject.h.orig	2007-08-20 21:00:58.000000000 -0500
+++ numpy/core/include/numpy/ufuncobject.h	2007-08-27 15:08:11.000000000 -0500
@@ -262,7 +262,10 @@
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
@@ -276,9 +279,9 @@
 	(void) fpsetsticky(0);						\
 	}
 
-#elif defined(__GLIBC__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__)
+#elif defined(__GLIBC__) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 #include <fenv.h>
 #elif defined(__CYGWIN__)
 #include "fenv/fenv.c"
