--- chrome/browser/performance_monitor/process_monitor.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -82,7 +82,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   lhs.cpu_usage += rhs.cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
