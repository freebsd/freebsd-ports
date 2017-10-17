--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2017-09-05 21:05:13.000000000 +0200
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc	2017-09-06 18:21:57.565534000 +0200
@@ -40,7 +40,9 @@
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
@@ -48,7 +50,7 @@
 #if defined(USE_X11)
 #include "ui/base/x/x11_util.h"
 #endif
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if defined(USE_OZONE) || defined(USE_X11)
 #include "ui/events/devices/input_device_event_observer.h"
