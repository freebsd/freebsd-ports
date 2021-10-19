--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2021-10-01 01:36:40 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -62,7 +62,9 @@
 // of lacros-chrome is complete.
 #if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
@@ -71,7 +73,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/base/x/x11_util.h"
 #endif
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 #if defined(USE_OZONE) || defined(USE_X11)
 #include "ui/events/devices/device_data_manager.h"
@@ -224,11 +226,13 @@ void RecordStartupMetrics() {
   base::UmaHistogramBoolean("Windows.ApplockerRunning", IsApplockerRunning());
 #endif  // defined(OS_WIN)
 
+#if !defined(OS_BSD)
   // TODO(crbug.com/1216328) Remove logging.
   LOG(ERROR) << "crbug.com/1216328: Checking Bluetooth availability started. "
                 "Please report if there is no report that this ends.";
   bluetooth_utility::ReportBluetoothAvailability();
   LOG(ERROR) << "crbug.com/1216328: Checking Bluetooth availability ended.";
+#endif
 
   // Record whether Chrome is the default browser or not.
   LOG(ERROR) << "crbug.com/1216328: Checking default browser status started. "
