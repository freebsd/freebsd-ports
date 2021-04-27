--- chrome/browser/performance_monitor/process_metrics_recorder.cc.orig	2021-04-22 07:55:58 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder.cc
@@ -58,7 +58,7 @@ void ProcessMetricsRecorder::OnMetricsSampled(
           kDiskUsageHistogramMin, kDiskUsageHistogramMax,
           kDiskUsageHistogramBucketCount);
 #endif
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.BrowserProcess",
@@ -82,7 +82,7 @@ void ProcessMetricsRecorder::OnMetricsSampled(
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.RendererProcess",
                               true);
       }
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000(
           "PerformanceMonitor.IdleWakeups.RendererProcess",
@@ -105,7 +105,7 @@ void ProcessMetricsRecorder::OnMetricsSampled(
                                   kHistogramMax, kHistogramBucketCount);
       if (metrics.cpu_usage > kHighCPUUtilizationThreshold)
         UMA_HISTOGRAM_BOOLEAN("PerformanceMonitor.HighCPU.GPUProcess", true);
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
       UMA_HISTOGRAM_COUNTS_10000("PerformanceMonitor.IdleWakeups.GPUProcess",
                                  metrics.idle_wakeups);
