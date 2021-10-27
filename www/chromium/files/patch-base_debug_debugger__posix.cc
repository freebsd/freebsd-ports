--- base/debug/debugger_posix.cc.orig	2021-09-24 04:25:55 UTC
+++ base/debug/debugger_posix.cc
@@ -92,7 +92,7 @@ bool BeingDebugged() {
     KERN_PROC,
     KERN_PROC_PID,
     getpid()
-#if defined(OS_OPENBSD)
+#if defined(OS_BSD) 
     , sizeof(struct kinfo_proc),
     0
 #endif
@@ -100,33 +100,35 @@ bool BeingDebugged() {
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
-  struct kinfo_proc info;
-  size_t info_size = sizeof(info);
+  struct kinfo_proc *info;
+  size_t info_size;
 
-#if defined(OS_OPENBSD)
   if (sysctl(mib, base::size(mib), NULL, &info_size, NULL, 0) < 0)
     return -1;
 
+  info = (struct kinfo_proc *)malloc(info_size);
   mib[5] = (info_size / sizeof(struct kinfo_proc));
-#endif
 
-  int sysctl_result = sysctl(mib, base::size(mib), &info, &info_size, NULL, 0);
+  int sysctl_result = sysctl(mib, base::size(mib), info, &info_size, NULL, 0);
   DCHECK_EQ(sysctl_result, 0);
   if (sysctl_result != 0) {
     is_set = true;
     being_debugged = false;
-    return being_debugged;
+    goto out;
   }
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
 #if defined(OS_FREEBSD)
-  being_debugged = (info.ki_flag & P_TRACED) != 0;
+  being_debugged = (info->ki_flag & P_TRACED) != 0;
 #elif defined(OS_BSD)
-  being_debugged = (info.p_flag & P_TRACED) != 0;
+  being_debugged = (info->p_flag & P_TRACED) != 0;
 #else
-  being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+  being_debugged = (info->kp_proc.p_flag & P_TRACED) != 0;
 #endif
+
+out:
+  free(info);
   return being_debugged;
 }
 
