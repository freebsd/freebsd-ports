--- base/process/process_metrics.cc.orig	2022-02-07 13:39:41 UTC
+++ base/process/process_metrics.cc
@@ -18,7 +18,7 @@ namespace base {
 namespace {
 
 #if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
 int CalculateEventsPerSecond(uint64_t event_count,
                              uint64_t* last_event_count,
                              base::TimeTicks* last_calculated) {
@@ -55,7 +55,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -74,7 +74,7 @@ Value SystemMetrics::ToValue() const {
   Value res(Value::Type::DICTIONARY);
 
   res.SetIntKey("committed_memory", static_cast<int>(committed_memory_));
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   Value meminfo = memory_info_.ToValue();
   Value vmstat = vmstat_info_.ToValue();
   meminfo.MergeDictionary(&vmstat);
@@ -126,7 +126,7 @@ double ProcessMetrics::GetPlatformIndependentCPUUsage(
 #endif
 
 #if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
