--- base/posix/can_lower_nice_to.cc.orig	2022-02-07 13:39:41 UTC
+++ base/posix/can_lower_nice_to.cc
@@ -11,8 +11,12 @@
 
 #include "build/build_config.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/param.h>
+#endif
+
 // Not defined on AIX by default.
-#if defined(OS_AIX)
+#if defined(OS_AIX) || defined(OS_BSD)
 #if defined(RLIMIT_NICE)
 #error Assumption about OS_AIX is incorrect
 #endif
