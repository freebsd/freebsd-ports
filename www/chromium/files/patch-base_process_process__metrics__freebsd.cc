--- base/process/process_metrics_freebsd.cc.orig	2016-03-25 13:04:44 UTC
+++ base/process/process_metrics_freebsd.cc
@@ -12,6 +12,9 @@
 #include "base/macros.h"
 #include "base/sys_info.h"
 
+#include <unistd.h> /* getpagesize() */
+#include <fcntl.h>  /* O_RDONLY */
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
@@ -121,4 +124,23 @@ size_t GetSystemCommitCharge() {
   return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
 }
 
+int GetNumberOfThreads(ProcessHandle process) {
+  // Taken from FreeBSD top (usr.bin/top/machine.c)
+
+  kvm_t* kd = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, "kvm_open");
+  if (kd == NULL)
+    return 0;
+
+  struct kinfo_proc* pbase;
+  int nproc;
+  pbase = kvm_getprocs(kd, KERN_PROC_PID, process, &nproc);
+  if (pbase == NULL)
+    return 0;
+
+  if (kvm_close(kd) == -1)
+    return 0;
+
+  return nproc;
+}
+
 }  // namespace base
