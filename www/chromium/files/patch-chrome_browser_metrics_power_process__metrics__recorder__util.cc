--- chrome/browser/metrics/power/process_metrics_recorder_util.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/metrics/power/process_metrics_recorder_util.cc
@@ -41,7 +41,7 @@ void RecordProcessHistograms(const char* histogram_suf
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
 #endif
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups.", histogram_suffix}),
       metrics.idle_wakeups);
