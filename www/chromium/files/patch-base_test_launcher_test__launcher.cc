--- base/test/launcher/test_launcher.cc.orig	2017-01-26 00:49:07 UTC
+++ base/test/launcher/test_launcher.cc
@@ -59,6 +59,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
