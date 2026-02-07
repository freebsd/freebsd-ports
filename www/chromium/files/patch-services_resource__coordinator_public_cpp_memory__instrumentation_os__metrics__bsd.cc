--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_bsd.cc.orig	2025-08-07 06:57:29 UTC
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_bsd.cc
@@ -0,0 +1,61 @@
+// Copyright 2022 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
+
+#include "base/notimplemented.h"
+
+#include "base/memory/page_size.h"
+#include "base/process/process.h"
+#include "base/process/process_handle.h"
+
+#include <sys/sysctl.h>
+
+#include <vector>
+
+#if BUILDFLAG(IS_OPENBSD)
+#define vm_rssize info.p_vm_rssize
+#elif BUILDFLAG(IS_FREEBSD)
+#include <sys/user.h>
+#define vm_rssize info.ki_rssize
+#endif
+
+namespace memory_instrumentation {
+
+// static
+bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
+                                 const MemDumpFlagSet& flags,
+                                 mojom::RawOSMemDump* dump) {
+  base::Process process = pid == base::kNullProcessId
+                              ? base::Process::Current()
+                              : base::Process::Open(pid);
+  const size_t kPageSize = base::GetPageSize();
+  struct kinfo_proc info;
+  size_t length = sizeof(struct kinfo_proc);
+#if BUILDFLAG(IS_OPENBSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process.Handle(),
+                static_cast<int>(length), 1 };
+#elif BUILDFLAG(IS_FREEBSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process.Handle() };
+#endif
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
+    return false;
+
+  dump->resident_set_kb = (vm_rssize * kPageSize) / 1024;
+  dump->platform_private_footprint->rss_anon_bytes =
+      vm_rssize * kPageSize;
+  dump->platform_private_footprint->vm_swap_bytes = 0;
+
+  return true;
+}
+
+// static
+std::vector<mojom::VmRegionPtr> OSMetrics::GetProcessMemoryMaps(
+    base::ProcessId) {
+  NOTIMPLEMENTED();
+  return std::vector<mojom::VmRegionPtr>();
+}
+
+}  // namespace memory_instrumentation
