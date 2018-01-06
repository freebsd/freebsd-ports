--- src/3rdparty/chromium/base/process/process_posix.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/process_posix.cc
@@ -21,8 +21,18 @@
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
@@ -184,13 +194,13 @@ bool WaitForExitWithTimeoutImpl(base::Pr
   base::ProcessHandle parent_pid = base::GetParentProcessId(handle);
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
@@ -257,12 +267,16 @@ Process Process::DeprecatedGetProcessFro
   return Process(handle);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 // static
 bool Process::CanBackgroundProcesses() {
   return false;
 }
-#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX)
+#elif defined(OS_FREEBSD)
+bool Process::CanBackgroundProcesses() {
+  return true;
+}
+#endif  // !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 
 bool Process::IsValid() const {
   return process_ != kNullProcessHandle;
@@ -365,15 +379,32 @@ bool Process::WaitForExitWithTimeout(Tim
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
+  DPCHECK(result == 0);
+  return result == 0;
+#endif // !defined(OS_FREEBSD)
 }
 #endif  // !defined(OS_LINUX) && !defined(OS_MACOSX)
 
