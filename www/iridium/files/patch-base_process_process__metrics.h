--- base/process/process_metrics.h.orig	2018-03-20 23:05:14.000000000 +0100
+++ base/process/process_metrics.h	2018-03-24 12:20:53.523721000 +0100
@@ -110,7 +110,7 @@
   size_t image;
 };
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -120,7 +120,7 @@
   int64_t minor;
   int64_t major;
 };
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Convert a POSIX timeval to microseconds.
 BASE_EXPORT int64_t TimeValToMicroseconds(const struct timeval& tv);
@@ -252,7 +252,7 @@
   // otherwise.
   bool GetIOCounters(IoCounters* io_counters) const;
 
-#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Returns the number of file descriptors currently open by the process, or
   // -1 on error.
   int GetOpenFdCount() const;
@@ -260,16 +260,16 @@
   // Returns the soft limit of file descriptors that can be opened by the
   // process, or -1 on error.
   int GetOpenFdSoftLimit() const;
-#endif  // defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_AIX) || defined(OS_ANDROID) || defined(OS_BSD)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
   // Minor and major page fault count as reported by /proc/[pid]/stat.
   // Returns true for success.
   bool GetPageFaultCounts(PageFaultCounts* counts) const;
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
   // Returns total memory usage of malloc.
   size_t GetMallocUsage();
@@ -289,7 +289,7 @@
   bool GetWorkingSetKBytesTotmaps(WorkingSetKBytes *ws_usage) const;
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_MACOSX)
@@ -310,7 +310,7 @@
   TimeTicks last_cpu_time_;
   int64_t last_system_time_;
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -358,7 +358,7 @@
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -391,7 +391,7 @@
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -406,7 +406,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -416,7 +416,7 @@
   int dirty = 0;
   int reclaimable = 0;
 #endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) ||
-        // defined(OS_FUCHSIA)
+        // defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   int shmem = 0;
@@ -444,7 +444,7 @@
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
