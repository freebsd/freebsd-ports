--- content/public/test/browser_test_base.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/public/test/browser_test_base.cc	2018-03-04 01:33:57.278528000 +0100
@@ -49,6 +49,10 @@
 #include "ui/gl/gl_implementation.h"
 #include "ui/gl/gl_switches.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
