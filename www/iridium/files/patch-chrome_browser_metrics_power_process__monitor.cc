--- chrome/browser/metrics/power/process_monitor.cc.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/metrics/power/process_monitor.cc
@@ -65,7 +65,7 @@ ProcessMonitor::Metrics SampleMetrics(base::ProcessMet
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -81,7 +81,7 @@ void ScaleMetrics(ProcessMonitor::Metrics* metrics, do
   metrics->cpu_usage *= factor;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics->idle_wakeups *= factor;
 #endif
 
@@ -172,7 +172,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   lhs.cpu_usage += rhs.cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
