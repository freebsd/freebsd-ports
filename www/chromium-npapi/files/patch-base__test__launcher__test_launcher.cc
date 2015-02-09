--- ./base/test/launcher/test_launcher.cc.orig	2014-04-30 22:41:42.000000000 +0200
+++ ./base/test/launcher/test_launcher.cc	2014-05-04 14:38:46.000000000 +0200
@@ -40,6 +40,10 @@
 #include "base/mac/scoped_nsautorelease_pool.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
