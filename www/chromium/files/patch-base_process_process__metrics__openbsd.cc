--- base/process/process_metrics_openbsd.cc.orig	2024-04-19 13:02:56 UTC
+++ base/process/process_metrics_openbsd.cc
@@ -6,73 +6,49 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <fcntl.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/vmmeter.h>
 #include <optional>
 
+#include <kvm.h>
+
 #include "base/memory/ptr_util.h"
+#include "base/values.h"
+#include "base/notreached.h"
 
 namespace base {
 
-namespace {
+ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process) {}
 
-static std::optional<int> GetProcessCPU(pid_t pid) {
+std::optional<TimeDelta> ProcessMetrics::GetCumulativeCPUUsage() {
   struct kinfo_proc info;
-  size_t length;
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, pid,
-                sizeof(struct kinfo_proc), 0 };
+  size_t length = sizeof(struct kinfo_proc);
+  struct timeval tv;
 
-  if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) < 0) {
-    return std::nullopt;
-  }
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc), 1 };
 
-  mib[5] = (length / sizeof(struct kinfo_proc));
-
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
-    return std::nullopt;
+    return std::optional(TimeDelta());
   }
 
-  return std::optional(info.p_pctcpu);
+  tv.tv_sec = info.p_rtime_sec;
+  tv.tv_usec = info.p_rtime_usec;
+
+  return std::optional(Microseconds(TimeValToMicroseconds(tv)));
 }
 
-}  // namespace
-
 // static
 std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
     ProcessHandle process) {
   return WrapUnique(new ProcessMetrics(process));
 }
 
-std::optional<double> ProcessMetrics::GetPlatformIndependentCPUUsage() {
-  TimeTicks time = TimeTicks::Now();
-
-  if (last_cpu_time_.is_zero()) {
-    // First call, just set the last values.
-    last_cpu_time_ = time;
-    return std::optional(0.0);
-  }
-
-  const std::optional<int> cpu = GetProcessCPU(process_);
-  if (!cpu.has_value()) {
-    return std::nullopt;
-  }
-
-  last_cpu_time_ = time;
-  return std::optional(double{cpu.value()} / FSCALE * 100.0);
-}
-
-std::optional<TimeDelta> ProcessMetrics::GetCumulativeCPUUsage() {
-  NOTREACHED();
-  return std::nullopt;
-}
-
-ProcessMetrics::ProcessMetrics(ProcessHandle process)
-    : process_(process),
-      last_cpu_(0) {}
-
 size_t GetSystemCommitCharge() {
   int mib[] = { CTL_VM, VM_METER };
-  int pagesize;
+  size_t pagesize;
   struct vmtotal vmtotal;
   unsigned long mem_total, mem_free, mem_inactive;
   size_t len = sizeof(vmtotal);
@@ -84,9 +60,136 @@ size_t GetSystemCommitCharge() {
   mem_free = vmtotal.t_free;
   mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
 
-  pagesize = getpagesize();
+  pagesize = checked_cast<size_t>(getpagesize());
 
   return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+int ProcessMetrics::GetOpenFdCount() const {
+#if 0
+  struct kinfo_file *files;
+  kvm_t *kd = NULL;
+  int total_count = 0;
+  char errbuf[_POSIX2_LINE_MAX];
+
+  if ((kd = kvm_openfiles(NULL, NULL, NULL, KVM_NO_FILES, errbuf)) == NULL)
+    goto out;
+  
+  if ((files = kvm_getfiles(kd, KERN_FILE_BYPID, process_,  
+        sizeof(struct kinfo_file), &total_count)) == NULL) {
+	  total_count = 0;
+	  goto out;
+  }
+
+  kvm_close(kd);
+
+out:
+  return total_count;
+#endif
+  return getdtablecount();
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  return getdtablesize();
+//  return GetMaxFds();
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo) {
+  NOTIMPLEMENTED_LOG_ONCE();
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
+Value::Dict SystemMemoryInfoKB::ToDict() const {
+  Value::Dict res;
+  res.Set("total", total);
+  res.Set("free", free);
+  res.Set("available", available);
+  res.Set("buffers", buffers);
+  res.Set("cached", cached);
+  res.Set("active_anon", active_anon);   
+  res.Set("inactive_anon", inactive_anon);
+  res.Set("active_file", active_file);
+  res.Set("inactive_file", inactive_file);
+  res.Set("swap_total", swap_total);
+  res.Set("swap_free", swap_free);
+  res.Set("swap_used", swap_total - swap_free);
+  res.Set("dirty", dirty);   
+  res.Set("reclaimable", reclaimable);
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+Value::Dict VmStatInfo::ToDict() const {
+  Value::Dict res;
+  res.Set("pswpin", static_cast<int>(pswpin));
+  res.Set("pswpout", static_cast<int>(pswpout));
+  res.Set("pgmajfault", static_cast<int>(pgmajfault));
+
+  NOTIMPLEMENTED();
+
+  return res;
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
+
+Value::Dict SystemDiskInfo::ToDict() const {
+  Value::Dict res;
+ 
+  // Write out uint64_t variables as doubles.
+  // Note: this may discard some precision, but for JS there's no other option.
+  res.Set("reads", static_cast<double>(reads));
+  res.Set("reads_merged", static_cast<double>(reads_merged));
+  res.Set("sectors_read", static_cast<double>(sectors_read));
+  res.Set("read_time", static_cast<double>(read_time));
+  res.Set("writes", static_cast<double>(writes));
+  res.Set("writes_merged", static_cast<double>(writes_merged));
+  res.Set("sectors_written", static_cast<double>(sectors_written));
+  res.Set("write_time", static_cast<double>(write_time));
+  res.Set("io", static_cast<double>(io));
+  res.Set("io_time", static_cast<double>(io_time));
+  res.Set("weighted_io_time", static_cast<double>(weighted_io_time));
+
+  NOTIMPLEMENTED();
+
+  return res;
 }
 
 }  // namespace base
