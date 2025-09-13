--- base/process/process_metrics_openbsd.cc.orig	2025-09-11 13:19:19 UTC
+++ base/process/process_metrics_openbsd.cc
@@ -6,73 +6,85 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/vmmeter.h>
 
+#include <kvm.h>
+
 #include "base/memory/ptr_util.h"
 #include "base/types/expected.h"
+#include "base/values.h"
+#include "base/notimplemented.h"
 
 namespace base {
 
-namespace {
+ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process) {}
 
-base::expected<int, ProcessCPUUsageError> GetProcessCPU(pid_t pid) {
+base::expected<ProcessMemoryInfo, ProcessUsageError>
+ProcessMetrics::GetMemoryInfo() const {
+  ProcessMemoryInfo memory_info;
   struct kinfo_proc info;
-  size_t length;
-  int mib[] = {
-      CTL_KERN, KERN_PROC, KERN_PROC_PID, pid, sizeof(struct kinfo_proc), 0};
+  size_t length = sizeof(struct kinfo_proc);
 
-  if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) < 0) {
-    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc), 1 };
+
+  if (process_ == 0) {
+    return base::unexpected(ProcessUsageError::kSystemError);
   }
 
-  mib[5] = (length / sizeof(struct kinfo_proc));
-
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
-    return base::unexpected(ProcessCPUUsageError::kSystemError);
+    return base::unexpected(ProcessUsageError::kSystemError);
   }
 
-  return base::ok(info.p_pctcpu);
-}
+  if (length == 0) {
+    return base::unexpected(ProcessUsageError::kProcessNotFound);
+  }
 
-}  // namespace
+  memory_info.resident_set_bytes =
+    checked_cast<uint64_t>(info.p_vm_rssize * getpagesize());
 
-// static
-std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
-    ProcessHandle process) {
-  return WrapUnique(new ProcessMetrics(process));
+  return memory_info;
 }
 
-base::expected<double, ProcessCPUUsageError>
-ProcessMetrics::GetPlatformIndependentCPUUsage() {
-  TimeTicks time = TimeTicks::Now();
+base::expected<TimeDelta, ProcessCPUUsageError>
+ProcessMetrics::GetCumulativeCPUUsage() {
+  struct kinfo_proc info;
+  size_t length = sizeof(struct kinfo_proc);
+  struct timeval tv;
 
-  if (last_cpu_time_.is_zero()) {
-    // First call, just set the last values.
-    last_cpu_time_ = time;
-    return base::ok(0.0);
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc), 1 };
+
+  if (process_ == 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
   }
 
-  const base::expected<int, ProcessCPUUsageError> cpu = GetProcessCPU(process_);
-  if (!cpu.has_value()) {
-    return base::unexpected(cpu.error());
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
   }
 
-  last_cpu_time_ = time;
-  return base::ok(double{cpu.value()} / FSCALE * 100.0);
+  if (length == 0) {
+    return base::unexpected(ProcessCPUUsageError::kProcessNotFound);
+  }
+
+  tv.tv_sec = info.p_rtime_sec;
+  tv.tv_usec = info.p_rtime_usec;
+
+  return base::ok(Microseconds(TimeValToMicroseconds(tv)));
 }
 
-base::expected<TimeDelta, ProcessCPUUsageError>
-ProcessMetrics::GetCumulativeCPUUsage() {
-  NOTREACHED();
+// static
+std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
+    ProcessHandle process) {
+  return WrapUnique(new ProcessMetrics(process));
 }
 
-ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process), last_cpu_(0) {}
-
 size_t GetSystemCommitCharge() {
   int mib[] = {CTL_VM, VM_METER};
-  int pagesize;
+  size_t pagesize;
   struct vmtotal vmtotal;
   unsigned long mem_total, mem_free, mem_inactive;
   size_t len = sizeof(vmtotal);
@@ -85,9 +97,60 @@ size_t GetSystemCommitCharge() {
   mem_free = vmtotal.t_free;
   mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
 
-  pagesize = getpagesize();
+  pagesize = checked_cast<size_t>(getpagesize());
 
   return mem_total - (mem_free * pagesize) - (mem_inactive * pagesize);
 }
+
+int ProcessMetrics::GetOpenFdCount() const {
+  return (process_ == getpid()) ? getdtablecount() : -1;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  return getdtablesize();
+}
+
+bool ProcessMetrics::GetPageFaultCounts(PageFaultCounts* counts) const {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo) {
+  NOTIMPLEMENTED();
+  return false;
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
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
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
+SystemDiskInfo::SystemDiskInfo(const SystemDiskInfo&) = default;
+
+SystemDiskInfo& SystemDiskInfo::operator=(const SystemDiskInfo&) = default;
 
 }  // namespace base
