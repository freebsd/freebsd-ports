--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -61,8 +61,10 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
+#if !defined(OS_BSD)
 #include <gnu/libc-version.h>
+#endif
 
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
@@ -223,15 +225,18 @@ void RecordStartupMetrics() {
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
 #if !BUILDFLAG(IS_LINUX)
+#error out
   LOG(ERROR) << "START: GetDefaultBrowser(). "
                 "If you don't see the END: message, this is crbug.com/1216328.";
   shell_integration::DefaultWebClientState default_state =
