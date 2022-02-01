--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2021-12-31 00:57:23 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -63,12 +63,14 @@
 // of lacros-chrome is complete.
 #if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
 #include "base/version.h"
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
 #if defined(USE_OZONE)
 #include "ui/events/devices/device_data_manager.h"
@@ -223,11 +225,13 @@ void RecordStartupMetrics() {
   base::UmaHistogramBoolean("Windows.ApplockerRunning", IsApplockerRunning());
 #endif  // defined(OS_WIN)
 
+#if !defined(OS_BSD)
   // TODO(crbug.com/1216328) Remove logging.
   LOG(ERROR) << "START: ReportBluetoothAvailability(). "
                 "If you don't see the END: message, this is crbug.com/1216328.";
   bluetooth_utility::ReportBluetoothAvailability();
   LOG(ERROR) << "END: ReportBluetoothAvailability()";
+#endif
 
   // Record whether Chrome is the default browser or not.
   // Disabled on Linux due to hanging browser tests, see crbug.com/1216328.
