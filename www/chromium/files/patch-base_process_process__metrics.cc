--- base/process/process_metrics.cc.orig	2019-04-30 22:22:28 UTC
+++ base/process/process_metrics.cc
@@ -126,7 +126,7 @@ double ProcessMetrics::GetPlatformIndependentCPUUsage(
 }
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
@@ -138,7 +138,7 @@ int ProcessMetrics::GetIdleWakeupsPerSecond() {
   NOTIMPLEMENTED();  // http://crbug.com/120488
   return 0;
 }
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX)
 int ProcessMetrics::CalculatePackageIdleWakeupsPerSecond(
