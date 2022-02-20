--- chrome/browser/performance_monitor/process_monitor.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/performance_monitor/process_monitor.h
@@ -56,7 +56,7 @@ class ProcessMonitor {
     double cpu_usage = 0.0;
 
 #if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
