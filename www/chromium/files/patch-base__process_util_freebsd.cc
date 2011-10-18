--- /dev/null	2011-10-02 18:27:33.000000000 +0300
+++ base/process_util_freebsd.cc	2011-10-02 18:26:22.000000000 +0300
@@ -0,0 +1,320 @@
+// Copyright (c) 2009 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process_util.h"
+
+#include <ctype.h>
+#include <dirent.h>
+#include <dlfcn.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <sys/wait.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <time.h>
+#include <unistd.h>
+
+#include "base/file_util.h"
+#include "base/logging.h"
+#include "base/string_number_conversions.h"
+#include "base/string_split.h"
+#include "base/string_tokenizer.h"
+#include "base/string_util.h"
+#include "base/sys_info.h"
+//#include "base/thread_restrictions.h"
+
+namespace base {
+
+ProcessId GetParentProcessId(ProcessHandle process) {
+  struct kinfo_proc info;
+  int mib[4];
+  size_t info_size = sizeof(info);
+  
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process;
+
+  if (sysctl(mib, 4, &info, &info_size, NULL, 0) < 0)
+    return -1;
+
+  return info.ki_ppid;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  char pathname[PATH_MAX];
+  int mib[4];
+  size_t len;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PATHNAME;
+  mib[3] = process;
+
+  len = sizeof(pathname);
+
+  if (sysctl(mib, 4, pathname, &len, NULL, 0) < 0 || len == 0)
+    return FilePath();
+
+  return FilePath(std::string(pathname));
+}
+
+ProcessIterator::ProcessIterator(const ProcessFilter* filter)
+  : index_of_kinfo_proc_(),
+  filter_(filter) {
+
+  int mib[4];
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_UID;
+  mib[3] = getuid();
+
+  bool done = false;
+  int try_num = 1;
+  const int max_tries = 10;
+
+  do {
+    size_t len = 0;
+    if (sysctl(mib, 4, NULL, &len, NULL, 0) <0 ){
+      LOG(ERROR) << "failed to get the size needed for the process list";
+      kinfo_procs_.resize(0);
+      done = true;
+    } else {
+      size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+      // Leave some spare room for process table growth (more could show up
+      // between when we check and now)
+      num_of_kinfo_proc += 16;
+      kinfo_procs_.resize(num_of_kinfo_proc);
+      len = num_of_kinfo_proc * sizeof(struct kinfo_proc);
+      if (sysctl(mib, 4, &kinfo_procs_[0], &len, NULL, 0) <0) {
+        // If we get a mem error, it just means we need a bigger buffer, so
+        // loop around again.  Anything else is a real error and give up.
+        if (errno != ENOMEM) {
+          LOG(ERROR) << "failed to get the process list";
+          kinfo_procs_.resize(0);
+          done = true;
+        }
+      } else {
+        // Got the list, just make sure we're sized exactly right
+        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+        kinfo_procs_.resize(num_of_kinfo_proc);
+        done = true;
+      }
+    }
+  } while (!done && (try_num++ < max_tries));
+
+  if (!done) {
+    LOG(ERROR) << "failed to collect the process list in a few tries";
+    kinfo_procs_.resize(0);
+  }
+}
+
+ProcessIterator::~ProcessIterator() {
+}
+
+bool ProcessIterator::CheckForNextProcess() {
+  std::string data;
+
+  for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++ index_of_kinfo_proc_) {
+    int mib[3];
+    size_t len;
+    struct kinfo_proc kinfo = kinfo_procs_[index_of_kinfo_proc_];
+
+    if ((kinfo.ki_pid > 0) && (kinfo.ki_stat == SZOMB))
+      continue;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC_ARGS;
+    mib[2] = kinfo.ki_pid;
+
+    len = 0;
+    if (sysctl(mib, 3, NULL, &len, NULL, 0) < 0) {
+      LOG(ERROR) << "failed to figure out the buffer size for a command line";
+      continue;
+    }
+
+    data.resize(len);
+
+    if (sysctl(mib, 3, &data[0], &len, NULL, 0) < 0) {
+      LOG(ERROR) << "failed to fetch a commandline";
+      continue;
+    }
+
+    std::string delimiters;
+    delimiters.push_back('\0');
+    Tokenize(data, delimiters, &entry_.cmd_line_args_);
+
+    size_t exec_name_end = data.find('\0');
+    if (exec_name_end == std::string::npos) {
+      LOG(ERROR) << "command line data didn't match expected format";
+      continue;
+    }
+
+    entry_.pid_ = kinfo.ki_pid;
+    entry_.ppid_ = kinfo.ki_ppid;
+    entry_.gid_ = kinfo.ki_pgid;
+
+    size_t last_slash = data.rfind('/', exec_name_end);
+    if (last_slash == std::string::npos)
+      entry_.exe_file_.assign(data, 0, exec_name_end);
+    else
+      entry_.exe_file_.assign(data, last_slash + 1,
+                              exec_name_end - last_slash - 1);
+
+    // Start w/ the next entry next time through
+    ++index_of_kinfo_proc_;
+
+    return true;
+  }
+  return false;
+}
+
+bool NamedProcessIterator::IncludeEntry() {
+  if(executable_name_ != entry().exe_file())
+    return false;
+
+  return ProcessIterator::IncludeEntry();
+}
+
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process)
+    : process_(process),
+      last_time_(0),
+      last_system_time_(0),
+      last_cpu_(0) {
+  processor_count_ = base::SysInfo::NumberOfProcessors();
+}
+
+// static
+ProcessMetrics* ProcessMetrics::CreateProcessMetrics(ProcessHandle process) {
+  return new ProcessMetrics(process);
+}
+
+size_t ProcessMetrics::GetPagefileUsage() const {
+	struct kinfo_proc info; 
+  int mib[4];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+
+  if (sysctl(mib, 4, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return info.ki_size;
+}
+
+size_t ProcessMetrics::GetPeakPagefileUsage() const {
+  return 0;
+}
+
+size_t ProcessMetrics::GetWorkingSetSize() const {
+	struct kinfo_proc info; 
+  int mib[4];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+
+  if (sysctl(mib, 4, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return info.ki_rssize * getpagesize();
+}
+
+size_t ProcessMetrics::GetPeakWorkingSetSize() const {
+  return 0;
+}
+
+bool ProcessMetrics::GetMemoryBytes(size_t* private_bytes,
+                                    size_t* shared_bytes) {
+  WorkingSetKBytes ws_usage;
+  if (!GetWorkingSetKBytes(&ws_usage))
+    return false;
+
+  if (private_bytes)
+    *private_bytes = ws_usage.priv << 10;
+
+  if (shared_bytes)
+    *shared_bytes = ws_usage.shared * 1024;
+
+  return true;
+}
+
+bool ProcessMetrics::GetWorkingSetKBytes(WorkingSetKBytes* ws_usage) const {
+// TODO(bapt) be sure we can't be precise
+  size_t priv = GetWorkingSetSize();
+  if (!priv)
+    return false;
+  ws_usage->priv = priv / 1024;
+  ws_usage->shareable = 0;
+  ws_usage->shared = 0;
+
+  return true;
+}
+
+bool ProcessMetrics::GetIOCounters(IoCounters* io_counters) const {
+  return false;
+}
+
+double ProcessMetrics::GetCPUUsage() {
+  struct kinfo_proc info;
+  int mib[4];
+  size_t info_size = sizeof(info);
+  
+  struct timeval now;
+  int retval = gettimeofday(&now, NULL);
+  if (retval)
+    return 0;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+
+  if (sysctl(mib, 4, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return (info.ki_pctcpu / FSCALE) * 100.0;
+}
+
+size_t GetSystemCommitCharge() {
+  int mib[2], pagesize;
+  unsigned long mem_total, mem_free, mem_inactive;
+  size_t len = sizeof(mem_total);
+
+  if (sysctl(mib, 2, &mem_total, &len, NULL, 0) < 0)
+    return 0;
+
+  len = sizeof(mem_free);
+  if (sysctlbyname("vm.stats.vm.v_free_count",  &mem_free, &len,  NULL, 0) < 0)
+    return 0;
+
+  len = sizeof(mem_inactive);
+  if (sysctlbyname("vm.stats.vm.v_inactive_count", &mem_inactive, &len, NULL, 0) < 0)
+    return 0;
+
+  pagesize = getpagesize();
+
+  return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+void EnableTerminationOnOutOfMemory() {
+  NOTIMPLEMENTED();
+  return;
+}
+
+bool AdjustOOMScore(ProcessId process, int score) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+} // namespace base
