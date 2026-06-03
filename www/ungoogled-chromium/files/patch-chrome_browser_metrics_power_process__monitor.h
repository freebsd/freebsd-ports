--- chrome/browser/metrics/power/process_monitor.h.orig	2026-04-15 11:25:12 UTC
+++ chrome/browser/metrics/power/process_monitor.h
@@ -88,7 +88,7 @@ class ProcessMonitor : public content::BrowserChildPro
     std::optional<double> cpu_usage;
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
     // Returns the number of average idle cpu wakeups per second since the last
     // time the metric was sampled.
     int idle_wakeups = 0;
