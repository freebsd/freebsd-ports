--- chrome/browser/metrics/power/process_monitor.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/metrics/power/process_monitor.h
@@ -48,7 +48,7 @@ class ProcessMetricsDelegate {
   GetPlatformIndependentCPUUsage() = 0;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   virtual int GetIdleWakeupsPerSecond() = 0;
 #endif
 
@@ -110,7 +110,7 @@ class ProcessMonitor : public content::BrowserChildPro
     std::optional<double> cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
