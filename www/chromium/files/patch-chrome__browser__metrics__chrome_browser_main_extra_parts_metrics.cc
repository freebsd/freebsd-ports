--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -27,12 +27,14 @@
 
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
 
 #if defined(OS_WIN)
 #include "chrome/installer/util/google_update_settings.h"
