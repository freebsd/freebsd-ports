--- chrome/browser/metrics/power/process_monitor.cc.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/metrics/power/process_monitor.cc
@@ -59,7 +59,7 @@ ProcessMonitor::Metrics SampleMetrics(base::ProcessMet
   metrics.precise_cpu_usage = process_metrics.GetPreciseCPUUsage();
 #endif
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -114,7 +114,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
