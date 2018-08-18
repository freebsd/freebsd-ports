--- base/process/process_handle_freebsd.cc.orig	2018-01-04 21:05:38.000000000 +0100
+++ base/process/process_handle_freebsd.cc	2018-01-27 02:11:02.948007000 +0100
@@ -16,10 +16,13 @@
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, arraysize(mib), &info, &length, NULL, 0) < 0)
+    return -1;
+
+  if (length < sizeof(struct kinfo_proc))
     return -1;
 
   return info.ki_ppid;
