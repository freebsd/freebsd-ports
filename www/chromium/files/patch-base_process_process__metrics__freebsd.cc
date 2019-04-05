--- base/process/process_metrics_freebsd.cc.orig	2019-03-21 01:36:27.000000000 +0100
+++ base/process/process_metrics_freebsd.cc	2019-03-24 22:18:22.764297000 +0100
@@ -5,6 +5,7 @@
 #include "base/process/process_metrics.h"
 
 #include <stddef.h>
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <unistd.h>
@@ -14,11 +15,15 @@
 #include "base/process/process_metrics_iocounters.h"
 #include "base/stl_util.h"
 
+#include <unistd.h> /* getpagesize() */
+#include <fcntl.h>  /* O_RDONLY */
+#include <kvm.h>
+#include <libutil.h>
+
 namespace base {
 
 ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process),
-      last_cpu_(0) {}
+    : process_(process) {}
 
 // static
 std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
@@ -69,4 +74,93 @@
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
+int ProcessMetrics::GetOpenFdCount() const {
+  struct kinfo_file * kif;
+  int cnt;
+
+  if ((kif = kinfo_getfile(process_, &cnt)) == NULL)
+    return -1;
+
+  free(kif);
+
+  return cnt;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  size_t length;
+  int total_count = 0;
+  int mib[] = { CTL_KERN, KERN_MAXFILESPERPROC };
+
+  length = sizeof(total_count);
+
+  if (sysctl(mib, base::size(mib), &total_count, &length, NULL, 0) < 0) {
+    total_count = -1;
+  }
+
+  return total_count;
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+   NOTIMPLEMENTED();
+   return 0;
+}
+
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
+}
 }  // namespace base
