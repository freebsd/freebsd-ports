--- chrome/browser/metrics/power/process_metrics_recorder_util.cc.orig	2026-04-15 12:07:04 UTC
+++ chrome/browser/metrics/power/process_metrics_recorder_util.cc
@@ -65,7 +65,7 @@ void RecordProcessHistograms(const std::string_view hi
                              const ProcessMonitor::Metrics& metrics) {
   RecordAverageCPUUsage(histogram_suffix, metrics.cpu_usage);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups2.", histogram_suffix}),
       metrics.idle_wakeups);
