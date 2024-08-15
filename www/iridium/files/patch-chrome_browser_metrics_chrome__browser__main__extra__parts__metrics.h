--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.h
@@ -29,7 +29,7 @@ class PowerMetricsReporter;
 class ProcessMonitor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class PressureMetricsReporter;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -119,7 +119,7 @@ class ChromeBrowserMainExtraPartsMetrics : public Chro
       performance_intervention_metrics_reporter_;
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reports pressure metrics.
   std::unique_ptr<PressureMetricsReporter> pressure_metrics_reporter_;
 #endif  // BUILDFLAG(IS_LINUX)
