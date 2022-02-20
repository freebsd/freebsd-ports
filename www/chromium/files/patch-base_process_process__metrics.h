--- base/process/process_metrics.h.orig	2022-02-07 13:39:41 UTC
+++ base/process/process_metrics.h
@@ -37,7 +37,7 @@
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
 #include <string>
 #include <utility>
 #include <vector>
@@ -53,7 +53,7 @@ class Value;
 // Full declaration is in process_metrics_iocounters.h.
 struct IoCounters;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -107,7 +107,7 @@ class BASE_EXPORT ProcessMetrics {
   // convenience wrapper for CreateProcessMetrics().
   static std::unique_ptr<ProcessMetrics> CreateCurrentProcessMetrics();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Resident Set Size is a Linux/Android specific memory concept. Do not
   // attempt to extend this to other platforms.
   BASE_EXPORT size_t GetResidentSetSize() const;
@@ -134,7 +134,7 @@ class BASE_EXPORT ProcessMetrics {
   TimeDelta GetCumulativeCPUUsage() WARN_UNUSED_RESULT;
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   // Emits the cumulative CPU usage for all currently active threads since they
   // were started into the output parameter (replacing its current contents).
   // Threads that have already terminated will not be reported. Thus, the sum of
@@ -217,7 +217,7 @@ class BASE_EXPORT ProcessMetrics {
   int GetOpenFdSoftLimit() const;
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
@@ -237,7 +237,7 @@ class BASE_EXPORT ProcessMetrics {
 #endif  // !defined(OS_MAC)
 
 #if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_APPLE)
@@ -248,7 +248,7 @@ class BASE_EXPORT ProcessMetrics {
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   CPU::CoreType GetCoreType(int core_index);
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) ||
         // defined(OS_AIX)
@@ -273,7 +273,7 @@ class BASE_EXPORT ProcessMetrics {
   uint64_t last_cumulative_disk_usage_ = 0;
 
 #if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -316,7 +316,7 @@ BASE_EXPORT void IncreaseFdLimitTo(unsigned int max_de
 
 #if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||      \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -351,7 +351,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -366,7 +366,7 @@ struct BASE_EXPORT SystemMemoryInfoKB {
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_AIX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -403,7 +403,7 @@ BASE_EXPORT bool GetSystemMemoryInfo(SystemMemoryInfoK
         // defined(OS_FUCHSIA)
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_AIX)
+    defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
@@ -590,7 +590,7 @@ class BASE_EXPORT SystemMetrics {
   FRIEND_TEST_ALL_PREFIXES(SystemMetricsTest, SystemMetrics);
 
   size_t committed_memory_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   SystemMemoryInfoKB memory_info_;
   VmStatInfo vmstat_info_;
   SystemDiskInfo disk_info_;
