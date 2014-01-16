--- base/test/launcher/test_launcher.cc.orig	2014-01-07 21:01:10.000000000 +0100
+++ base/test/launcher/test_launcher.cc	2014-01-13 01:36:07.000000000 +0100
@@ -36,6 +36,10 @@
 #include "base/mac/scoped_nsautorelease_pool.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
