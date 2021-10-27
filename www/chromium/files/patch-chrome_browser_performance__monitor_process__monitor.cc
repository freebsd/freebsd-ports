--- chrome/browser/performance_monitor/process_monitor.cc.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -76,7 +76,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
                                     const ProcessMonitor::Metrics& rhs) {
   lhs.cpu_usage += rhs.cpu_usage;
 
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
