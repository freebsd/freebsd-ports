--- chrome/browser/performance_monitor/process_monitor.cc.orig	2021-04-22 07:56:37 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -82,7 +82,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   lhs.disk_usage += rhs.disk_usage;
 #endif
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
