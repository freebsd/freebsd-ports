--- srclib/apr/include/apr.h.in.orig	Fri Nov 15 17:33:00 2002
+++ srclib/apr/include/apr.h.in	Fri Nov 15 17:33:10 2002
@@ -299,11 +299,11 @@
 #endif
 
 /* header files for PATH_MAX, _POSIX_PATH_MAX */
-#if APR_HAVE_SYS_SYSLIMITS_H
-#include <sys/syslimits.h>
-#endif
 #if APR_HAVE_LIMITS_H
 #include <limits.h>
+#endif
+#if APR_HAVE_SYS_SYSLIMITS_H
+#include <sys/syslimits.h>
 #endif
 
 #if defined(PATH_MAX)
