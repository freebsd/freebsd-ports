--- base/process/process_metrics_freebsd.cc.orig	2018-06-13 00:10:01.000000000 +0200
+++ base/process/process_metrics_freebsd.cc	2018-07-20 00:07:42.005261000 +0200
@@ -13,6 +13,10 @@
 #include "base/memory/ptr_util.h"
 #include "base/process/process_metrics_iocounters.h"
 
+#include <unistd.h> /* getpagesize() */
+#include <fcntl.h>  /* O_RDONLY */
+#include <kvm.h>
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
@@ -61,6 +65,65 @@
   pagesize = getpagesize();
 
   return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
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
+bool GetSystemMemoryInfo(SystemMemoryInfoKB *meminfo) {
+  unsigned int mem_total, mem_free, swap_total, swap_used;
+  size_t length;
+  int pagesizeKB;
+
+  pagesizeKB = getpagesize() / 1024;
+
+  length = sizeof(mem_total);
+  if (sysctlbyname("vm.stats.vm.v_page_count", &mem_total,
+      &length, NULL, 0) != 0 || length != sizeof(mem_total))
+    return false;
+
+  length = sizeof(mem_free);
+  if (sysctlbyname("vm.stats.vm.v_free_count", &mem_free, &length, NULL, 0)
+      != 0 || length != sizeof(mem_free))
+    return false;
+
+  length = sizeof(swap_total);
+  if (sysctlbyname("vm.swap_size", &swap_total, &length, NULL, 0)
+      != 0 || length != sizeof(swap_total))
+    return false;
+
+  length = sizeof(swap_used);
+  if (sysctlbyname("vm.swap_anon_use", &swap_used, &length, NULL, 0)
+      != 0 || length != sizeof(swap_used))
+    return false;
+
+  meminfo->total = mem_total * pagesizeKB;
+  meminfo->free = mem_free * pagesizeKB;
+  meminfo->swap_total = swap_total * pagesizeKB;
+  meminfo->swap_free = (swap_total - swap_used) * pagesizeKB;
+
+  return true;
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+   NOTIMPLEMENTED();
+   return 0;
 }
 
 }  // namespace base
