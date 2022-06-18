--- base/process/process_metrics.cc.orig	2022-06-17 14:20:10 UTC
+++ base/process/process_metrics.cc
@@ -17,7 +17,7 @@ namespace base {
 namespace {
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 int CalculateEventsPerSecond(uint64_t event_count,
                              uint64_t* last_event_count,
                              base::TimeTicks* last_calculated) {
@@ -54,7 +54,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -73,7 +73,7 @@ Value SystemMetrics::ToValue() const {
   Value res(Value::Type::DICTIONARY);
 
   res.SetIntKey("committed_memory", static_cast<int>(committed_memory_));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   Value meminfo = memory_info_.ToValue();
   Value vmstat = vmstat_info_.ToValue();
   meminfo.MergeDictionary(&vmstat);
@@ -99,7 +99,7 @@ std::unique_ptr<ProcessMetrics> ProcessMetrics::Create
 #endif  // !BUILDFLAG(IS_MAC)
 }
 
-#if !BUILDFLAG(IS_FREEBSD) || !BUILDFLAG(IS_POSIX)
+#if !BUILDFLAG(IS_BSD) || !BUILDFLAG(IS_POSIX)
 double ProcessMetrics::GetPlatformIndependentCPUUsage() {
   TimeDelta cumulative_cpu = GetCumulativeCPUUsage();
   TimeTicks time = TimeTicks::Now();
@@ -150,7 +150,7 @@ double ProcessMetrics::GetPreciseCPUUsage() {
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
