--- chrome/browser/performance_monitor/process_monitor.h.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/performance_monitor/process_monitor.h
@@ -57,7 +57,7 @@ class ProcessMonitor {
     // can exceed 100% in multi-thread processes running on multi-core systems.
     double cpu_usage = 0.0;
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
