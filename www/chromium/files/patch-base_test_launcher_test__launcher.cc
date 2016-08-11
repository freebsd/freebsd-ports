--- base/test/launcher/test_launcher.cc.orig	2016-05-11 19:02:11 UTC
+++ base/test/launcher/test_launcher.cc
@@ -52,6 +52,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
