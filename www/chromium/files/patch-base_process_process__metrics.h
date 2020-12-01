--- base/process/process_metrics.h.orig	2020-11-13 06:36:34 UTC
+++ base/process/process_metrics.h
@@ -47,7 +47,7 @@ namespace base {
 // Full declaration is in process_metrics_iocounters.h.
 struct IoCounters;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -57,7 +57,7 @@ struct PageFaultCounts {
   int64_t minor;
   int64_t major;
 };
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Convert a POSIX timeval to microseconds.
 BASE_EXPORT int64_t TimeValToMicroseconds(const struct timeval& tv);
@@ -98,7 +98,7 @@ class BASE_EXPORT ProcessMetrics {
   // convenience wrapper for CreateProcessMetrics().
   static std::unique_ptr<ProcessMetrics> CreateCurrentProcessMetrics();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Resident Set Size is a Linux/Android specific memory concept. Do not
   // attempt to extend this to other platforms.
   BASE_EXPORT size_t GetResidentSetSize() const;
@@ -124,7 +124,7 @@ class BASE_EXPORT ProcessMetrics {
   // will result in a time delta of 2 seconds/per 1 wall-clock second.
   TimeDelta GetCumulativeCPUUsage();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
   // Emits the cumulative CPU usage for all currently active threads since they
   // were started into the output parameter (replacing its current contents).
@@ -159,7 +159,7 @@ class BASE_EXPORT ProcessMetrics {
   bool ParseProcTimeInState(const std::string& content,
                             PlatformThreadId tid,
                             TimeInStatePerThread& time_in_state_per_thread);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) ||
         // defined(OS_AIX)
 
   // Returns the number of average idle cpu wakeups per second since the last
@@ -216,14 +216,14 @@ class BASE_EXPORT ProcessMetrics {
   int GetOpenFdSoftLimit() const;
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
   // Minor and major page fault count as reported by /proc/[pid]/stat.
   // Returns true for success.
   bool GetPageFaultCounts(PageFaultCounts* counts) const;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
   // Returns total memory usage of malloc.
   size_t GetMallocUsage();
@@ -235,7 +235,7 @@ class BASE_EXPORT ProcessMetrics {
   ProcessMetrics(ProcessHandle process, PortProvider* port_provider);
 #endif  // !defined(OS_MAC)
 
-#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
@@ -246,10 +246,10 @@ class BASE_EXPORT ProcessMetrics {
       uint64_t absolute_package_idle_wakeups);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
   CPU::CoreType GetCoreType(int core_index);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) ||
         // defined(OS_AIX)
 
 #if defined(OS_WIN)
@@ -271,7 +271,7 @@ class BASE_EXPORT ProcessMetrics {
   // Number of bytes transferred to/from disk in bytes.
   uint64_t last_cumulative_disk_usage_ = 0;
 
-#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
@@ -323,7 +323,7 @@ BASE_EXPORT size_t GetHandleLimit();
 BASE_EXPORT void IncreaseFdLimitTo(unsigned int max_descriptors);
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||      \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_AIX) || \
     defined(OS_FUCHSIA)
 // Data about system-wide memory consumption. Values are in KB. Available on
@@ -358,7 +358,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
@@ -373,7 +373,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int swap_free = 0;
 #endif
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX) || defined(OS_FUCHSIA)
   int buffers = 0;
   int cached = 0;
@@ -383,7 +383,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
   int inactive_file = 0;
   int dirty = 0;
   int reclaimable = 0;
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_AIX) defined(OS_FUCHSIA)
 
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
@@ -406,11 +406,11 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 // Exposed for memory debugging widget.
 BASE_EXPORT bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo);
 
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) defined(OS_ANDROID) || defined(OS_AIX) ||
         // defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
@@ -485,7 +485,7 @@ BASE_EXPORT bool GetSystemDiskInfo(SystemDiskInfo* dis
 // Returns the amount of time spent in user space since boot across all CPUs.
 BASE_EXPORT TimeDelta GetUserCpuTimeSinceBoot();
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) ||
         // defined(OS_AIX)
 
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
@@ -597,7 +597,7 @@ class BASE_EXPORT SystemMetrics {
   FRIEND_TEST_ALL_PREFIXES(SystemMetricsTest, SystemMetrics);
 
   size_t committed_memory_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   SystemMemoryInfoKB memory_info_;
   VmStatInfo vmstat_info_;
   SystemDiskInfo disk_info_;
