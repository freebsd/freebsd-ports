--- base/process/process_metrics_freebsd.cc.orig	2025-09-06 10:01:20 UTC
+++ base/process/process_metrics_freebsd.cc
@@ -3,41 +3,92 @@
 // found in the LICENSE file.
 
 #include "base/process/process_metrics.h"
+#include "base/notimplemented.h"
 
 #include <stddef.h>
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <unistd.h>
 
+#include <fcntl.h> /* O_RDONLY */
+#include <kvm.h>
+#include <libutil.h>
+
 #include "base/memory/ptr_util.h"
+#include "base/values.h"
 
 namespace base {
+namespace {
+int GetPageShift() {
+  int pagesize = getpagesize();
+  int pageshift = 0;
 
-ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process), last_cpu_(0) {}
+  while (pagesize > 1) {
+    pageshift++;
+    pagesize >>= 1;
+  }
 
+  return pageshift;
+}
+}
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process) {}
+
 // static
 std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
     ProcessHandle process) {
   return WrapUnique(new ProcessMetrics(process));
 }
 
-base::expected<double, ProcessCPUUsageError>
-ProcessMetrics::GetPlatformIndependentCPUUsage() {
-  struct kinfo_proc info;
-  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, process_};
-  size_t length = sizeof(info);
+base::expected<ProcessMemoryInfo, ProcessUsageError>
+ProcessMetrics::GetMemoryInfo() const {
+  ProcessMemoryInfo memory_info;
+  kvm_t *kd = kvm_open(nullptr, "/dev/null", nullptr, O_RDONLY, "kvm_open");
+  struct kinfo_proc *pp;
+  int nproc;
 
-  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
-    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  if (kd == nullptr) {
+    return base::unexpected(ProcessUsageError::kSystemError);
   }
 
-  return base::ok(double{info.ki_pctcpu} / FSCALE * 100.0);
+  if ((pp = kvm_getprocs(kd, KERN_PROC_PID, process_, &nproc)) == nullptr) {
+    kvm_close(kd);
+    return base::unexpected(ProcessUsageError::kProcessNotFound);
+  }
+
+  if (nproc > 0) {
+    memory_info.resident_set_bytes = pp->ki_rssize << GetPageShift();
+  } else {
+    kvm_close(kd);
+    return base::unexpected(ProcessUsageError::kProcessNotFound);
+  }
+
+  kvm_close(kd);
+  return memory_info;
 }
 
 base::expected<TimeDelta, ProcessCPUUsageError>
 ProcessMetrics::GetCumulativeCPUUsage() {
-  NOTREACHED();
+  struct kinfo_proc info;
+  size_t length = sizeof(struct kinfo_proc);
+  struct timeval tv;
+
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_ };
+
+  if (process_ == 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  }
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  }
+
+  if (length == 0) {
+    return base::unexpected(ProcessCPUUsageError::kProcessNotFound);
+  }
+
+  return base::ok(Microseconds(info.ki_runtime));
 }
 
 size_t GetSystemCommitCharge() {
@@ -65,5 +116,118 @@ size_t GetSystemCommitCharge() {
 
   return mem_total - (mem_free * pagesize) - (mem_inactive * pagesize);
 }
+
+int64_t GetNumberOfThreads(ProcessHandle process) {
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
+  if (sysctl(mib, std::size(mib), &total_count, &length, NULL, 0) < 0) {
+    total_count = -1;
+  }
+
+  return total_count;
+}
+
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+bool GetSystemDiskInfo(SystemDiskInfo* diskinfo) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool GetVmStatInfo(VmStatInfo* vmstat) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+SystemDiskInfo::SystemDiskInfo() {
+  reads = 0;
+  reads_merged = 0;
+  sectors_read = 0;
+  read_time = 0;
+  writes = 0;
+  writes_merged = 0;
+  sectors_written = 0;
+  write_time = 0;
+  io = 0;
+  io_time = 0;
+  weighted_io_time = 0;
+}
+
+SystemDiskInfo::SystemDiskInfo(const SystemDiskInfo& other) = default;
+
+SystemDiskInfo& SystemDiskInfo::operator=(const SystemDiskInfo&) = default;
 
 }  // namespace base
