--- chrome/browser/performance_monitor/process_monitor.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/performance_monitor/process_monitor.cc
@@ -83,7 +83,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   lhs.cpu_usage += rhs.cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
