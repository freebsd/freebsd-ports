--- base/process_util_posix.cc.orig	2011-09-12 11:35:34.000000000 +0300
+++ base/process_util_posix.cc	2011-09-15 02:07:17.000000000 +0300
@@ -33,6 +33,11 @@
 #include "base/threading/thread_restrictions.h"
 #include "base/time.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/event.h>
+#include <sys/ucontext.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <crt_externs.h>
 #include <sys/event.h>
@@ -767,8 +772,8 @@
   return false;
 }
 
-#if defined(OS_MACOSX)
-// Using kqueue on Mac so that we can wait on non-child processes.
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+// Using kqueue on BSD so that we can wait on non-child processes.
 // We can't use kqueues on child processes because we need to reap
 // our own children using wait.
 static bool WaitForSingleNonChildProcess(ProcessHandle handle,
@@ -826,19 +831,19 @@
     }
   }
 }
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_FREEBSD
 
 bool WaitForSingleProcess(ProcessHandle handle, int64 wait_milliseconds) {
   ProcessHandle parent_pid = GetParentProcessId(handle);
   ProcessHandle our_pid = Process::Current().handle();
   if (parent_pid != our_pid) {
-#if defined(OS_MACOSX)
-    // On Mac we can wait on non child processes.
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
+    // On BSD we can wait on non child processes.
     return WaitForSingleNonChildProcess(handle, wait_milliseconds);
 #else
     // Currently on Linux we can't handle non child processes.
     NOTIMPLEMENTED();
-#endif  // OS_MACOSX
+#endif  // OS_MACOSX || OS_FREEBSD
   }
   bool waitpid_success;
   int status;
