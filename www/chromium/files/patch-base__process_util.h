--- base/process_util.h.orig	2011-09-14 11:01:29.000000000 +0300
+++ base/process_util.h	2011-09-30 23:12:21.000000000 +0300
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
@@ -163,7 +167,7 @@
 // Win XP SP1 as well.
 BASE_API ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Returns the path to the executable of the given process.
 BASE_API FilePath GetProcessExecutablePath(ProcessHandle process);
 
@@ -467,7 +471,7 @@
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   std::vector<kinfo_proc> kinfo_procs_;
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
