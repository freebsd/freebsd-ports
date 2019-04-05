--- base/process/process_metrics.cc.orig	2019-03-21 01:36:27.000000000 +0100
+++ base/process/process_metrics.cc	2019-03-24 19:52:47.516944000 +0100
@@ -126,7 +126,7 @@
 }
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
@@ -138,7 +138,7 @@
   NOTIMPLEMENTED();  // http://crbug.com/120488
   return 0;
 }
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 int ProcessMetrics::CalculatePackageIdleWakeupsPerSecond(
