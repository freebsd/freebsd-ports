--- content/browser/child_thread_type_switcher_linux.cc.orig	2026-08-13 07:41:05 UTC
+++ content/browser/child_thread_type_switcher_linux.cc
@@ -6,6 +6,7 @@
 
 #include "base/linux_util.h"
 #include "base/logging.h"
+#include "base/notimplemented.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/process/process_handle.h"
 #include "base/task/single_thread_task_runner.h"
@@ -21,6 +22,9 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
                                    base::ThreadType thread_type) {
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
 
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   bool ns_pid_supported = false;
   pid_t peer_tid =
       base::FindThreadID(peer_pid, ns_tid.raw(), &ns_pid_supported);
@@ -42,6 +46,7 @@ void SetThreadTypeOnLauncherThread(base::ProcessId pee
 
   base::PlatformThread::SetThreadType(
       peer_pid, base::PlatformThreadId(peer_tid), thread_type);
+#endif
 }
 
 void SetThreadTypesOnLauncherThread(
