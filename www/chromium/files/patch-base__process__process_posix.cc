--- base/process/process_posix.cc.orig	2015-08-22 15:01:51.000000000 -0400
+++ base/process/process_posix.cc	2015-09-05 09:44:45.526291000 -0400
@@ -17,8 +17,18 @@
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
@@ -83,7 +93,7 @@
   return ret_pid > 0;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // Using kqueue on Mac so that we can wait on non-child processes.
 // We can't use kqueues on child processes because we need to reap
 // our own children using wait.
@@ -180,7 +190,7 @@
   base::ProcessHandle parent_pid = base::GetParentProcessId(handle);
   base::ProcessHandle our_pid = base::GetCurrentProcessHandle();
   if (parent_pid != our_pid) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
     // On Mac we can wait on non child processes.
     return WaitForSingleNonChildProcess(handle, timeout);
 #else
@@ -255,13 +265,6 @@
   return Process(handle);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX)
-// static
-bool Process::CanBackgroundProcesses() {
-  return false;
-}
-#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX)
-
 bool Process::IsValid() const {
   return process_ != kNullProcessHandle;
 }
@@ -357,18 +360,27 @@
 }
 
 #if !defined(OS_LINUX) && !defined(OS_MACOSX)
+// static
+bool Process::CanBackgroundProcesses() {
+  return true;
+}
+
 bool Process::IsProcessBackgrounded() const {
-  // See SetProcessBackgrounded().
   DCHECK(IsValid());
-  return false;
+  return GetPriority() == kBackgroundPriority;
 }
 
 bool Process::SetProcessBackgrounded(bool value) {
-  // Not implemented for POSIX systems other than Mac and Linux. With POSIX, if
-  // we were to lower the process priority we wouldn't be able to raise it back
-  // to its initial priority.
-  NOTIMPLEMENTED();
-  return false;
+  DCHECK(IsValid());
+
+  if (!CanBackgroundProcesses())
+    return false;
+
+  int priority = value ? kBackgroundPriority : kForegroundPriority;
+  int result   = setpriority(PRIO_PROCESS, process_, priority);
+
+  DPCHECK(result == 0);
+  return result == 0;
 }
 #endif  // !defined(OS_LINUX) && !defined(OS_MACOSX)
 
