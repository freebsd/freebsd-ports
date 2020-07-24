--- base/process/internal_linux.h.orig	2020-03-16 18:39:41 UTC
+++ base/process/internal_linux.h
@@ -14,6 +14,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
@@ -50,6 +52,14 @@ bool ParseProcStats(const std::string& stats_data,
 // If the ordering ever changes, carefully review functions that use these
 // values.
 enum ProcStatsFields {
+#if defined(OS_BSD)
+  VM_COMM = 0,         // Command name.
+  VM_PPID = 2,         // Parent process id.
+  VM_PGRP = 3,         // Process group id.
+  VM_STARTTIME = 7,    // The process start time.
+  VM_UTIME = 8,        // The user time.
+  VM_STIME = 9,        // The system time
+#else
   VM_COMM = 1,         // Filename of executable, without parentheses.
   VM_STATE = 2,        // Letter indicating the state of the process.
   VM_PPID = 3,         // PID of the parent.
@@ -62,6 +72,7 @@ enum ProcStatsFields {
   VM_STARTTIME = 21,   // The time the process started in clock ticks.
   VM_VSIZE = 22,       // Virtual memory size in bytes.
   VM_RSS = 23,         // Resident Set Size in pages.
+#endif
 };
 
 // Reads the |field_num|th field from |proc_stats|. Returns 0 on failure.
