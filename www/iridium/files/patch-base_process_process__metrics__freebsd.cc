--- base/process/process_metrics_freebsd.cc.orig	2017-04-19 19:06:28 UTC
+++ base/process/process_metrics_freebsd.cc
@@ -13,6 +13,9 @@
 #include "base/memory/ptr_util.h"
 #include "base/sys_info.h"
 
+#include <unistd.h> /* getpagesize() */
+#include <fcntl.h>  /* O_RDONLY */
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
@@ -122,4 +125,23 @@ size_t GetSystemCommitCharge() {
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
