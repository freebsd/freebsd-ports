--- base/process/process_info_linux.cc.orig	2016-03-25 13:04:44 UTC
+++ base/process/process_info_linux.cc
@@ -11,10 +11,28 @@
 #include "base/process/process_handle.h"
 #include "base/time/time.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 namespace base {
 
 // static
 const Time CurrentProcessInfo::CreationTime() {
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid() };
+  struct kinfo_proc proc;
+  size_t len = sizeof(struct kinfo_proc);
+  if (sysctl(mib, arraysize(mib), &proc, &len, NULL, 0) < 0)
+    return Time();
+#if defined(__DragonFly__)
+  return Time::FromTimeVal(proc.kp_start);
+#else
+  return Time::FromTimeVal(proc.ki_start);
+#endif
+#else
   ProcessHandle pid = GetCurrentProcessHandle();
   int64_t start_ticks =
       internal::ReadProcStatsAndGetFieldAsInt64(pid, internal::VM_STARTTIME);
@@ -23,6 +41,7 @@ const Time CurrentProcessInfo::CreationT
   Time boot_time = internal::GetBootTime();
   DCHECK(!boot_time.is_null());
   return Time(boot_time + start_offset);
+#endif
 }
 
 }  // namespace base
