--- chrome/browser/performance_monitor/process_monitor.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -80,7 +80,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   lhs.cpu_usage += rhs.cpu_usage;
 
 #if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
