--- base/process_util.h.orig	2011-11-01 10:42:54.000000000 +0200
+++ base/process_util.h	2011-11-21 23:05:53.000000000 +0200
@@ -14,14 +14,14 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_MACOSX) || defined(OS_OPENBSD)
+#elif defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
 // kinfo_proc is defined in <sys/sysctl.h>, but this forward declaration
 // is sufficient for the vector<kinfo_proc> below.
 struct kinfo_proc;
 // malloc_zone_t is defined in <malloc/malloc.h>, but this forward declaration
 // is sufficient for GetPurgeableZone() below.
 typedef struct _malloc_zone_t malloc_zone_t;
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
 #include <mach/mach.h>
 #endif
 #elif defined(OS_POSIX)
@@ -166,7 +166,7 @@
 // Win XP SP1 as well.
 BASE_EXPORT ProcessId GetProcId(ProcessHandle process);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
 // Returns the path to the executable of the given process.
 BASE_EXPORT FilePath GetProcessExecutablePath(ProcessHandle process);
 
@@ -528,7 +528,7 @@
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_MACOSX) || defined(OS_OPENBSD)
+#elif defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   std::vector<kinfo_proc> kinfo_procs_;
   size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX)
