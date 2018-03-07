--- base/process/process_metrics.h.orig	2018-02-24 16:25:08.000000000 +0100
+++ base/process/process_metrics.h	2018-03-03 19:17:04.829273000 +0100
@@ -103,7 +103,7 @@
   size_t image;
 };
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // Minor and major page fault counts since the process creation.
 // Both counts are process-wide, and exclude child processes.
 //
@@ -245,7 +245,7 @@
   // otherwise.
   bool GetIOCounters(IoCounters* io_counters) const;
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Returns the number of file descriptors currently open by the process, or
   // -1 on error.
   int GetOpenFdCount() const;
@@ -255,7 +255,7 @@
   int GetOpenFdSoftLimit() const;
 #endif  // defined(OS_LINUX) || defined(OS_AIX)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Bytes of swap as reported by /proc/[pid]/status.
   uint64_t GetVmSwapBytes() const;
 
@@ -282,7 +282,7 @@
   bool GetWorkingSetKBytesTotmaps(WorkingSetKBytes *ws_usage) const;
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   int CalculateIdleWakeupsPerSecond(uint64_t absolute_idle_wakeups);
 #endif
 #if defined(OS_MACOSX)
@@ -303,7 +303,7 @@
   TimeTicks last_cpu_time_;
   int64_t last_system_time_;
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
   // Same thing for idle wakeups.
   TimeTicks last_idle_wakeups_time_;
   uint64_t last_absolute_idle_wakeups_;
@@ -351,7 +351,7 @@
 #endif  // defined(OS_POSIX)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Data about system-wide memory consumption. Values are in KB. Available on
 // Windows, Mac, Linux, Android and Chrome OS.
 //
@@ -384,7 +384,7 @@
   int avail_phys = 0;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
   // This provides an estimate of available memory as described here:
   // https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=34e431b0ae398fc54ea69ff85ec700722c9da773
   // NOTE: this is ONLY valid in kernels 3.14 and up.  Its value will always
@@ -399,7 +399,7 @@
 #endif
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_AIX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   int buffers = 0;
   int cached = 0;
   int active_anon = 0;
@@ -437,7 +437,7 @@
 #endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
         // defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_FUCHSIA)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 // Parse the data found in /proc/<pid>/stat and return the sum of the
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
