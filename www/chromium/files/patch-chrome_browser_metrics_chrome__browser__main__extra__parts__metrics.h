--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h.orig	2023-07-16 15:47:57 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h
@@ -32,7 +32,7 @@ class PowerMetricsReporter;
 class ProcessMonitor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class PressureMetricsReporter;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -133,7 +133,7 @@ class ChromeBrowserMainExtraPartsMetrics : public Chro
   std::unique_ptr<BatteryDischargeReporter> battery_discharge_reporter_;
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reports pressure metrics.
   std::unique_ptr<PressureMetricsReporter> pressure_metrics_reporter_;
 #endif  // BUILDFLAG(IS_LINUX)
