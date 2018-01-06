--- src/3rdparty/chromium/base/process/process_handle_freebsd.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/process/process_handle_freebsd.cc
@@ -16,7 +16,7 @@ namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, arraysize(mib), &info, &length, NULL, 0) < 0)
