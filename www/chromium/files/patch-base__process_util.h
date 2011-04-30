--- base/process_util.h.orig	2011-04-15 11:01:37.000000000 +0300
+++ base/process_util.h	2011-04-15 21:36:54.331640613 +0300
@@ -28,6 +28,10 @@
 #include <sys/types.h>
 #endif
 
+#if defined(OS_FREEBSD)
+struct kinfo_proc;
+#endif  /* defined(OS_FREEBSD) */
+
 #include <list>
 #include <string>
 #include <utility>
@@ -161,7 +165,7 @@
 // Win XP SP1 as well.
 ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Returns the path to the executable of the given process.
 FilePath GetProcessExecutablePath(ProcessHandle process);
 
@@ -170,13 +174,14 @@
 // Exposed for testing.
 int ParseProcStatCPU(const std::string& input);
 
+#elif defined(OS_LINUX)
 static const char kAdjustOOMScoreSwitch[] = "--adjust-oom-score";
 
 // This adjusts /proc/process/oom_adj so the Linux OOM killer will prefer
 // certain process types over others. The range for the adjustment is
 // [-17,15], with [0,15] being user accessible.
 bool AdjustOOMScore(ProcessId process, int score);
-#endif
+#endif  /* defined(OS_LINUX) || defined(OS_FREEBSD) */
 
 #if defined(OS_POSIX)
 // Returns the ID for the parent of the given process.
@@ -439,7 +444,7 @@
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   std::vector<kinfo_proc> kinfo_procs_;
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
