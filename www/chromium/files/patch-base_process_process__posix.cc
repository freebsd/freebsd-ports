--- base/process/process_posix.cc.orig	2025-08-07 06:57:29 UTC
+++ base/process/process_posix.cc
@@ -25,10 +25,15 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include <sys/event.h>
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/types.h>
+#include <sys/sysctl.h> 
+#endif
+
 #if BUILDFLAG(CLANG_PROFILING)
 #include "base/test/clang_profiling.h"
 #endif
@@ -104,7 +109,7 @@ bool WaitpidWithTimeout(base::ProcessHandle handle,
 }
 #endif
 
-#if BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Using kqueue on Mac so that we can wait on non-child processes.
 // We can't use kqueues on child processes because we need to reap
 // our own children using wait.
@@ -387,7 +392,7 @@ bool Process::WaitForExitWithTimeoutImpl(base::Process
   const bool exited = (parent_pid < 0);
 
   if (!exited && parent_pid != our_pid) {
-#if BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // On Mac we can wait on non child processes.
     return WaitForSingleNonChildProcess(handle, timeout);
 #else
@@ -424,7 +429,56 @@ void Process::Exited(int exit_code) const {
 
 int Process::GetOSPriority() const {
   DCHECK(IsValid());
+// avoid pledge(2) violation
+#if BUILDFLAG(IS_BSD)
+  return 0;
+#else
   return getpriority(PRIO_PROCESS, static_cast<id_t>(process_));
+#endif
 }
+
+Time Process::CreationTime() const {
+// avoid ps pledge in the network process
+#if !BUILDFLAG(IS_BSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid(),
+               sizeof(struct kinfo_proc), 0 };
+  struct kinfo_proc *info = nullptr;
+  size_t info_size;
+#endif
+  Time ct = Time();
+
+#if !BUILDFLAG(IS_BSD)
+  if (sysctl(mib, std::size(mib), NULL, &info_size, NULL, 0) < 0)
+    goto out;
+
+  mib[5] = (info_size / sizeof(struct kinfo_proc));
+  if ((info = reinterpret_cast<kinfo_proc*>(malloc(info_size))) == NULL)
+    goto out;
+
+  if (sysctl(mib, std::size(mib), info, &info_size, NULL, 0) < 0)
+    goto out;
+
+  ct = Time::FromTimeT(info->p_ustart_sec);
+
+out:
+  if (info)
+    free(info);
+#endif
+  return ct;
+}
+
+#if BUILDFLAG(IS_BSD)
+Process::Priority Process::GetPriority() const {
+  return Priority::kUserBlocking;
+}
+
+bool Process::SetPriority(Priority priority) {
+  return false;
+}
+
+bool Process::CanSetPriority() {
+  return false;
+}
+#endif
 
 }  // namespace base
