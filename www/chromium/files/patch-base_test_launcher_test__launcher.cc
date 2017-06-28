--- base/test/launcher/test_launcher.cc.orig	2017-06-05 19:03:00 UTC
+++ base/test/launcher/test_launcher.cc
@@ -61,6 +61,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
