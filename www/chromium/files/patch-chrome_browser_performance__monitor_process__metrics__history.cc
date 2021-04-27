--- chrome/browser/performance_monitor/process_metrics_history.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/performance_monitor/process_metrics_history.cc
@@ -42,7 +42,7 @@ ProcessMonitor::Metrics ProcessMetricsHistory::SampleM
 #if defined(OS_WIN)
   metrics.disk_usage = process_metrics_->GetDiskUsageBytesPerSecond();
 #endif
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   metrics.idle_wakeups = process_metrics_->GetIdleWakeupsPerSecond();
 #endif
