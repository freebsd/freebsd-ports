--- base/process_util_posix.cc.orig	2012-01-29 14:28:45.000000000 +0200
+++ base/process_util_posix.cc	2012-01-29 14:29:58.000000000 +0200
@@ -886,7 +886,7 @@
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 // Using kqueue on Mac so that we can wait on non-child processes.
 // We can't use kqueues on child processes because we need to reap
 // our own children using wait.
@@ -976,19 +976,19 @@
 
   return true;
 }
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_FREEBSD
 
 bool WaitForSingleProcess(ProcessHandle handle, int64 wait_milliseconds) {
   ProcessHandle parent_pid = GetParentProcessId(handle);
   ProcessHandle our_pid = Process::Current().handle();
   if (parent_pid != our_pid) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     // On Mac we can wait on non child processes.
     return WaitForSingleNonChildProcess(handle, wait_milliseconds);
 #else
     // Currently on Linux we can't handle non child processes.
     NOTIMPLEMENTED();
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_FREEBSD
   }
 
   bool waitpid_success;
