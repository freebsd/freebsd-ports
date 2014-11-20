--- base/test/launcher/test_launcher.cc.orig	2014-10-10 09:15:29 UTC
+++ base/test/launcher/test_launcher.cc
@@ -45,6 +45,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
