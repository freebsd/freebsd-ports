--- chrome/browser/performance_monitor/process_monitor.h.orig	2021-04-22 07:56:51 UTC
+++ chrome/browser/performance_monitor/process_monitor.h
@@ -51,7 +51,7 @@ class ProcessMonitor {
     uint64_t disk_usage = 0;
 #endif
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
