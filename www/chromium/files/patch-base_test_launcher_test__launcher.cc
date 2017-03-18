--- base/test/launcher/test_launcher.cc.orig	2017-03-09 20:04:26 UTC
+++ base/test/launcher/test_launcher.cc
@@ -60,6 +60,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
