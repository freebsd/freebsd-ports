--- mozilla/ipc/chromium/src/base/third_party/nspr/prcpucfg.h~
+++ mozilla/ipc/chromium/src/base/third_party/nspr/prcpucfg.h
@@ -34,7 +34,7 @@
 #include "base/third_party/nspr/prcpucfg_win.h"
 #elif defined(__APPLE__)
 #include "base/third_party/nspr/prcpucfg_mac.h"
-#elif defined(__linux__) || defined(ANDROID)
+#elif defined(__FreeBSD__) || defined(ANDROID)
 #include "base/third_party/nspr/prcpucfg_linux.h"
 #else
 #error Provide a prcpucfg.h appropriate for your platform
