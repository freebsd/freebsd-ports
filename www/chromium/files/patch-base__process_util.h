--- base/process_util.h.orig	2011-03-21 07:38:40.133112029 +0200
+++ base/process_util.h	2011-03-21 07:51:24.970111144 +0200
@@ -28,6 +28,10 @@
 #include <sys/types.h>
 #endif
 
+#if defined(OS_FREEBSD)
+struct kinfo_proc;
+#endif
+
 #include <list>
 #include <string>
 #include <utility>
@@ -161,7 +165,7 @@
 // Win XP SP1 as well.
 ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Returns the ID for the parent of the given process.
 ProcessId GetParentProcessId(ProcessHandle process);
 
@@ -172,7 +176,9 @@
 // CPU-related ticks.  Returns -1 on parse error.
 // Exposed for testing.
 int ParseProcStatCPU(const std::string& input);
+#endif
 
+#if defined(OS_LINUX)
 static const char kAdjustOOMScoreSwitch[] = "--adjust-oom-score";
 
 // This adjusts /proc/process/oom_adj so the Linux OOM killer will prefer
@@ -439,7 +445,7 @@
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   std::vector<kinfo_proc> kinfo_procs_;
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
