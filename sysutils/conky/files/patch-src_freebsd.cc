--- src/freebsd.cc.orig	2018-12-16 17:16:51 UTC
+++ src/freebsd.cc
@@ -254,6 +254,8 @@ int update_total_processes(void) {
   kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 
   info.procs = n_processes;
+
+  return 0;
 }
 
 int update_running_processes(void) {
