--- base/process/process_posix.cc.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/process/process_posix.cc	2017-08-02 19:38:18.657740000 +0200
@@ -22,8 +22,18 @@
 #include <sys/event.h>
 #endif
 
+#if defined(OS_BSD)
+#include <signal.h>
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/time.h>
+#endif
+
 namespace {
 
+const int kBackgroundPriority = 5;
+const int kForegroundPriority = 0;
+
 #if !defined(OS_NACL_NONSFI)
 
 bool WaitpidWithTimeout(base::ProcessHandle handle,
@@ -186,13 +196,13 @@
   base::ProcessHandle our_pid = base::GetCurrentProcessHandle();
 
   if (parent_pid != our_pid) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
     // On Mac we can wait on non child processes.
-    return WaitForSingleNonChildProcess(handle, timeout);
+    /* return WaitForSingleNonChildProcess(handle, timeout); */
 #else
     // Currently on Linux we can't handle non child processes.
     NOTIMPLEMENTED();
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_BSD
   }
 
   int status;
@@ -258,12 +268,16 @@
   return Process(handle);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX) && !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
   return false;
 }
-#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
+#elif defined(OS_FREEBSD)
+bool Process::CanBackgroundProcesses() {
+  return true;
+}
+#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX) && !defined(OS_BSD)
 
 // static
 void Process::TerminateCurrentProcessImmediately(int exit_code) {
@@ -371,15 +385,31 @@
 bool Process::IsProcessBackgrounded() const {
   // See SetProcessBackgrounded().
   DCHECK(IsValid());
+#if defined(OS_FREEBSD)
+  return true;
+#else
   return false;
+#endif
 }
 
 bool Process::SetProcessBackgrounded(bool value) {
+#if !defined(OS_FREEBSD)
   // Not implemented for POSIX systems other than Linux and Mac. With POSIX, if
   // we were to lower the process priority we wouldn't be able to raise it back
   // to its initial priority.
   NOTIMPLEMENTED();
   return false;
+#else
+  DCHECK(IsValid());
+
+  if (!CanBackgroundProcesses())
+    return false;
+
+  int priority = value ? kBackgroundPriority : kForegroundPriority;
+  int result   = setpriority(PRIO_PROCESS, process_, priority);
+
+  return result == 0;
+#endif // !defined(OS_FREEBSD)
 }
 #endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
 
