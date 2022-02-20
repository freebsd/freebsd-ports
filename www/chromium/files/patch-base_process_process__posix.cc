--- base/process/process_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ base/process/process_posix.cc
@@ -27,6 +27,11 @@
 #include <sys/event.h>
 #endif
 
+#if defined(OS_BSD)
+#include <sys/types.h>
+#include <sys/sysctl.h> 
+#endif
+
 #if BUILDFLAG(CLANG_PROFILING)
 #include "base/test/clang_profiling.h"
 #endif
@@ -358,7 +363,55 @@ void Process::Exited(int exit_code) const {}
 
 int Process::GetPriority() const {
   DCHECK(IsValid());
+// avoid pledge(2) violation
+#if defined(OS_BSD)
+  return 0;
+#else
   return getpriority(PRIO_PROCESS, process_);
+#endif
+}
+
+Time Process::CreationTime() const {
+// avoid ps pledge in the network process
+#if !defined(OS_BSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid(),
+               sizeof(struct kinfo_proc), 0 };
+  struct kinfo_proc *info = nullptr;
+  size_t info_size;
+#endif
+  Time ct = Time();
+
+#if !defined(OS_BSD)
+  if (sysctl(mib, base::size(mib), NULL, &info_size, NULL, 0) < 0)
+    goto out;
+
+  mib[5] = (info_size / sizeof(struct kinfo_proc));
+  if ((info = reinterpret_cast<kinfo_proc*>(malloc(info_size))) == NULL)
+    goto out;
+
+  if (sysctl(mib, base::size(mib), info, &info_size, NULL, 0) < 0)
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
+bool Process::IsProcessBackgrounded() const {
+  return false;
+}
+ 
+bool Process::SetProcessBackgrounded(bool value) {
+  return false;
+}
+ 
+// static
+bool Process::CanBackgroundProcesses() {
+  return false;
 }
 
 }  // namespace base
