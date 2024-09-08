--- chrome/browser/metrics/power/process_monitor.cc.orig	2024-08-26 12:06:38 UTC
+++ chrome/browser/metrics/power/process_monitor.cc
@@ -65,7 +65,7 @@ ProcessMonitor::Metrics SampleMetrics(base::ProcessMet
       process_metrics.GetPlatformIndependentCPUUsage());
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics.idle_wakeups = process_metrics.GetIdleWakeupsPerSecond();
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -83,7 +83,7 @@ void ScaleMetrics(ProcessMonitor::Metrics* metrics, do
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   metrics->idle_wakeups *= factor;
 #endif
 
@@ -158,7 +158,7 @@ ProcessMonitor::Metrics& operator+=(ProcessMonitor::Me
   }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   lhs.idle_wakeups += rhs.idle_wakeups;
 #endif
 
