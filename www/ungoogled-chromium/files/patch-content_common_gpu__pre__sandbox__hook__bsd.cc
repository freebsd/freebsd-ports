--- content/common/gpu_pre_sandbox_hook_bsd.cc.orig	2025-09-10 13:22:16 UTC
+++ content/common/gpu_pre_sandbox_hook_bsd.cc
@@ -0,0 +1,68 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "content/common/gpu_pre_sandbox_hook_bsd.h"
+
+#include <dlfcn.h>
+#include <errno.h>
+#include <sys/stat.h>
+
+#include <memory>
+#include <sstream>
+#include <utility>
+#include <vector>
+
+#include "base/base_paths.h"
+#include "base/files/file_enumerator.h"
+#include "base/files/file_path.h"
+#include "base/files/scoped_file.h"
+#include "base/functional/bind.h"
+#include "base/logging.h"
+#include "base/path_service.h"
+#include "base/strings/stringprintf.h"
+#include "build/build_config.h"
+#include "build/buildflag.h"
+#include "build/chromeos_buildflags.h"
+#include "content/public/common/content_switches.h"
+#include "media/gpu/buildflags.h"
+
+namespace content {
+namespace {
+
+constexpr int dlopen_flag = RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE;
+
+void LoadVulkanLibraries() {
+  // Try to preload Vulkan libraries. Failure is not an error as not all may be
+  // present.
+  const char* kLibraries[] = {
+      "libvulkan.so",
+      "libvulkan_intel.so",
+      "libvulkan_intel_hasvk.so",
+      "libvulkan_radeon.so",
+  };
+  for (const auto* library : kLibraries) {
+    dlopen(library, dlopen_flag);
+  }
+}
+
+}  // namespace
+
+bool LoadLibrariesForGpu(
+    const sandbox::policy::SandboxSeccompBPF::Options& options) {
+  LoadVulkanLibraries();
+
+  return true;
+}
+
+bool GpuPreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+  if (!LoadLibrariesForGpu(options))
+    return false;
+
+  // TODO(tsepez): enable namspace sandbox here once crashes are understood.
+
+  errno = 0;
+  return true;
+}
+
+}  // namespace content
