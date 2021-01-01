--- chrome/browser/performance_monitor/process_metrics_history.cc.orig	2019-10-21 19:06:22 UTC
+++ chrome/browser/performance_monitor/process_metrics_history.cc
@@ -47,7 +47,7 @@ void ProcessMetricsHistory::SampleMetrics() {
 #if defined(OS_WIN)
   disk_usage_ = process_metrics_->GetDiskUsageBytesPerSecond();
 #endif
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   idle_wakeups_ = process_metrics_->GetIdleWakeupsPerSecond();
 #endif
 #if defined(OS_MACOSX)
@@ -88,7 +88,7 @@ void ProcessMetricsHistory::RunPerformanceTriggers() {
           kDiskUsageHistogramMin, kDiskUsageHistogramMax,
           kDiskUsageHistogramBucketCount);
 #endif
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.BrowserProcess", idle_wakeups_);
 #endif
@@ -109,7 +109,7 @@ void ProcessMetricsHistory::RunPerformanceTriggers() {
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.RendererProcess",
                               true);
       }
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.RendererProcess", idle_wakeups_);
 #endif
@@ -129,7 +129,7 @@ void ProcessMetricsHistory::RunPerformanceTriggers() {
                                   kHistogramBucketCount);
       if (cpu_usage_ > kHighCPUUtilizationThreshold)
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.GPUProcess", true);
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
       UMA_HISTOGRAM_COUNTS_10000("PerformanceMonitor.IdleWakeups.GPUProcess",
                                  idle_wakeups_);
 #endif
