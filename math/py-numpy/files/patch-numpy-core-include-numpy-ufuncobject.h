--- numpy/core/include/numpy/ufuncobject.h.orig	Mon Oct 23 15:13:40 2006
+++ numpy/core/include/numpy/ufuncobject.h	Sat Dec  9 22:51:47 2006
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
 
-#elif defined(linux) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__)
+#elif defined(linux) || defined(__APPLE__) || defined(__CYGWIN__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 
-#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__)
+#if defined(__GLIBC__) || defined(__APPLE__) || defined(__MINGW32__) || (defined(__FreeBSD__) && (__FreeBSD_version >= 502114))
 #include <fenv.h>
 #elif defined(__CYGWIN__)
 #include "fenv/fenv.c"
