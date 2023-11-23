--- src/3rdparty/chromium/base/process/process_metrics.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/base/process/process_metrics.cc
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
@@ -73,7 +73,7 @@ Value::Dict SystemMetrics::ToDict() const {
   Value::Dict res;
 
   res.Set("committed_memory", static_cast<int>(committed_memory_));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   Value::Dict meminfo = memory_info_.ToDict();
   meminfo.Merge(vmstat_info_.ToDict());
   res.Set("meminfo", std::move(meminfo));
@@ -98,7 +98,6 @@ std::unique_ptr<ProcessMetrics> ProcessMetrics::Create
 #endif  // !BUILDFLAG(IS_MAC)
 }
 
-#if !BUILDFLAG(IS_FREEBSD) || !BUILDFLAG(IS_POSIX)
 double ProcessMetrics::GetPlatformIndependentCPUUsage(
     TimeDelta cumulative_cpu) {
   TimeTicks time = TimeTicks::Now();
@@ -124,7 +123,6 @@ double ProcessMetrics::GetPlatformIndependentCPUUsage(
 double ProcessMetrics::GetPlatformIndependentCPUUsage() {
   return GetPlatformIndependentCPUUsage(GetCumulativeCPUUsage());
 }
-#endif
 
 #if BUILDFLAG(IS_WIN)
 double ProcessMetrics::GetPreciseCPUUsage(TimeDelta cumulative_cpu) {
@@ -155,7 +153,7 @@ double ProcessMetrics::GetPreciseCPUUsage() {
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 int ProcessMetrics::CalculateIdleWakeupsPerSecond(
     uint64_t absolute_idle_wakeups) {
   return CalculateEventsPerSecond(absolute_idle_wakeups,
