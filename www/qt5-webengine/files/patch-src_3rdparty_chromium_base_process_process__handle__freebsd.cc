--- src/3rdparty/chromium/base/process/process_handle_freebsd.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/process/process_handle_freebsd.cc
@@ -16,10 +16,13 @@ namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
+    return -1;
+
+  if (length < sizeof(struct kinfo_proc))
     return -1;
 
   return info.ki_ppid;
