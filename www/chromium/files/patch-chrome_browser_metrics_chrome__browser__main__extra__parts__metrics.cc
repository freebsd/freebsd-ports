--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2023-07-16 15:47:57 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -67,8 +67,10 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(__GLIBC__) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(__GLIBC__) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
+#if !BUILDFLAG(IS_BSD)
 #include <gnu/libc-version.h>
+#endif
 
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
@@ -102,7 +104,7 @@
 #include "chromeos/startup/startup_switches.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/pressure/pressure_metrics_reporter.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -111,7 +113,7 @@
 #include "components/user_manager/user_manager.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/power_metrics/system_power_monitor.h"
 #endif
 
@@ -533,7 +535,7 @@ void RecordStartupMetrics() {
 
   // Record whether Chrome is the default browser or not.
   // Disabled on Linux due to hanging browser tests, see crbug.com/1216328.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   shell_integration::DefaultWebClientState default_state =
       shell_integration::GetDefaultBrowser();
   base::UmaHistogramEnumeration("DefaultBrowser.State", default_state,
@@ -742,11 +744,11 @@ void ChromeBrowserMainExtraPartsMetrics::PostBrowserSt
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pressure_metrics_reporter_ = std::make_unique<PressureMetricsReporter>();
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::trace_event::TraceLog::GetInstance()->AddEnabledStateObserver(
       power_metrics::SystemPowerMonitor::GetInstance());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
