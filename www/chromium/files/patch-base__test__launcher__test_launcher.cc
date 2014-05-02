--- ./base/test/launcher/test_launcher.cc.orig	2014-04-24 22:36:09.000000000 +0200
+++ ./base/test/launcher/test_launcher.cc	2014-04-24 23:23:41.000000000 +0200
@@ -39,6 +39,10 @@
 #include "base/mac/scoped_nsautorelease_pool.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
