--- chrome/browser/performance_monitor/process_metrics_recorder_util.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder_util.cc
@@ -42,7 +42,7 @@ void RecordProcessHistograms(const char* histogram_suf
       metrics.cpu_usage * kCPUUsageFactor, kCPUUsageHistogramMin,
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::JoinString({"PerformanceMonitor.IdleWakeups.", histogram_suffix},
                        ""),
