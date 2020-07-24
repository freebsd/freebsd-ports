--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -47,7 +47,9 @@
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
@@ -55,7 +57,7 @@
 #if defined(USE_X11)
 #include "ui/base/x/x11_util.h"
 #endif
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if defined(USE_OZONE) || defined(USE_X11)
 #include "ui/events/devices/device_data_manager.h"
