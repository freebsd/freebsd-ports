--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -39,12 +39,14 @@
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/version.h"
 #if defined(USE_X11)
 #include "ui/base/x/x11_util.h"
 #endif
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif
 
 #if defined(USE_OZONE) || defined(USE_X11)
 #include "ui/events/devices/input_device_event_observer.h"
