--- base/process/process_handle_freebsd.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/process/process_handle_freebsd.cc	2016-10-26 19:55:22.341492000 +0300
@@ -16,7 +16,7 @@
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, arraysize(mib), &info, &length, NULL, 0) < 0)
