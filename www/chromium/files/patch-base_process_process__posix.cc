--- base/process/process_posix.cc.orig	2017-12-15 02:04:05.000000000 +0100
+++ base/process/process_posix.cc	2017-12-23 21:14:03.546283000 +0100
@@ -22,8 +22,17 @@
 #include <sys/event.h>
 #endif
 
+#if defined(OS_BSD)
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
@@ -263,12 +272,10 @@
   return Process(handle);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
 // static
 bool Process::CanBackgroundProcesses() {
-  return false;
+  return true;
 }
-#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
 
 // static
 void Process::TerminateCurrentProcessImmediately(int exit_code) {
@@ -372,21 +379,23 @@
   return WaitForExitWithTimeoutImpl(Handle(), exit_code, timeout);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
 bool Process::IsProcessBackgrounded() const {
   // See SetProcessBackgrounded().
   DCHECK(IsValid());
-  return false;
+  return GetPriority() == kBackgroundPriority;
 }
 
-bool Process::SetProcessBackgrounded(bool value) {
-  // Not implemented for POSIX systems other than Linux and Mac. With POSIX, if
-  // we were to lower the process priority we wouldn't be able to raise it back
-  // to its initial priority.
-  NOTIMPLEMENTED();
-  return false;
+bool Process::SetProcessBackgrounded(bool background) {
+  DCHECK(IsValid());
+
+  if (!CanBackgroundProcesses())
+    return false;
+
+  int priority = background ? kBackgroundPriority : kForegroundPriority;
+  int result = setpriority(PRIO_PROCESS, process_, priority);
+  DPCHECK(result == 0);
+  return result == 0;
 }
-#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_AIX)
 
 int Process::GetPriority() const {
   DCHECK(IsValid());
