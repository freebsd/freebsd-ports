--- chrome/browser/performance_monitor/process_metrics_history.h.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/performance_monitor/process_metrics_history.h
@@ -71,7 +71,7 @@ class ProcessMetricsHistory {
   uint64_t disk_usage_ = 0;
 #endif
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   int idle_wakeups_ = 0;
 #endif
