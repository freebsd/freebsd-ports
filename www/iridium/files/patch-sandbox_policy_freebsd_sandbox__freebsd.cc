--- sandbox/policy/freebsd/sandbox_freebsd.cc.orig	2025-09-11 13:19:19 UTC
+++ sandbox/policy/freebsd/sandbox_freebsd.cc
@@ -0,0 +1,210 @@
+// Copyright (c) 2012 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+
+#include <dirent.h>
+#include <fcntl.h>
+#include <stdint.h>
+#include <sys/resource.h>
+#include <sys/stat.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <unistd.h>
+
+#include <limits>
+#include <memory>
+#include <string>
+#include <vector>
+
+#include "base/command_line.h"
+#include "base/debug/stack_trace.h"
+#include "base/feature_list.h"
+#include "base/files/file_path.h"
+#include "base/files/file_util.h"
+#include "base/files/scoped_file.h"
+#include "base/logging.h"
+#include "base/memory/singleton.h"
+#include "base/path_service.h"
+#include "base/posix/eintr_wrapper.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/system/sys_info.h"
+#include "base/threading/thread.h"
+#include "base/time/time.h"
+#include "build/build_config.h"
+#include "crypto/crypto_buildflags.h"
+#include "sandbox/constants.h"
+#include "sandbox/linux/services/credentials.h"
+#include "sandbox/linux/services/namespace_sandbox.h"
+#include "sandbox/linux/services/proc_util.h"
+#include "sandbox/linux/services/resource_limits.h"
+#include "sandbox/linux/services/thread_helpers.h"
+#include "sandbox/linux/syscall_broker/broker_command.h"
+#include "sandbox/linux/syscall_broker/broker_process.h"
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/policy/sandbox_type.h"
+#include "sandbox/policy/mojom/sandbox.mojom.h"
+#include "sandbox/policy/switches.h"
+#include "sandbox/sandbox_buildflags.h" 
+
+#if BUILDFLAG(USING_SANITIZER)
+#include <sanitizer/common_interface_defs.h>
+#endif
+
+#if BUILDFLAG(USE_NSS_CERTS)
+#include "crypto/nss_util.h"
+#endif
+
+#include "third_party/boringssl/src/include/openssl/crypto.h"
+
+#include "ui/gfx/font_util.h"
+
+namespace sandbox {
+namespace policy {
+
+SandboxLinux::SandboxLinux()
+    : sandbox_status_flags_(kInvalid),
+      pre_initialized_(false),
+      initialize_sandbox_ran_(false),
+      broker_process_(nullptr) {
+}
+
+SandboxLinux::~SandboxLinux() {
+  if (pre_initialized_) {
+    CHECK(initialize_sandbox_ran_);
+  }
+}
+
+SandboxLinux* SandboxLinux::GetInstance() {
+  SandboxLinux* instance = base::Singleton<SandboxLinux>::get();
+  CHECK(instance);
+  return instance;
+}
+
+void SandboxLinux::StopThread(base::Thread* thread) {
+  DCHECK(thread);
+  thread->Stop();
+}
+
+void SandboxLinux::PreinitializeSandbox(sandbox::mojom::Sandbox sandbox_type) {
+  CHECK(!pre_initialized_);
+#if BUILDFLAG(USING_SANITIZER)
+  // Sanitizers need to open some resources before the sandbox is enabled.
+  // This should not fork, not launch threads, not open a directory.
+  __sanitizer_sandbox_on_notify(sanitizer_args());
+  sanitizer_args_.reset();
+#endif
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  const std::string process_type =
+      command_line->GetSwitchValueASCII(switches::kProcessType);
+
+  base::SysInfo::AmountOfPhysicalMemory();
+  base::SysInfo::NumberOfProcessors();
+  base::SysInfo::CPUModelName();
+
+  switch (sandbox_type) {
+    case sandbox::mojom::Sandbox::kNoSandbox:
+    {
+#if BUILDFLAG(USE_NSS_CERTS)
+      // The main process has to initialize the ~/.pki dir which won't work
+      // after unveil(2).
+      crypto::EnsureNSSInit();
+#endif
+      CRYPTO_pre_sandbox_init();
+
+      base::FilePath cache_directory, local_directory;
+
+      base::PathService::Get(base::DIR_CACHE, &cache_directory);
+      base::PathService::Get(base::DIR_HOME, &local_directory);   
+
+      cache_directory = cache_directory.AppendASCII("iridium");
+      local_directory = local_directory.AppendASCII(".local").AppendASCII("share").AppendASCII("applications");
+
+      if (!base::CreateDirectory(cache_directory)) {
+        LOG(ERROR) << "Failed to create " << cache_directory.value() << " directory.";
+      }
+
+      if (!base::CreateDirectory(local_directory)) {
+        LOG(ERROR) << "Failed to create " << local_directory.value() << " directory.";
+      }
+
+      break;
+    }
+    case sandbox::mojom::Sandbox::kRenderer:
+      gfx::InitializeFonts();
+      break;
+    default:
+      break;
+  }
+
+  pre_initialized_ = true;
+}
+
+bool SandboxLinux::InitializeSandbox(sandbox::mojom::Sandbox sandbox_type,
+                                     SandboxLinux::PreSandboxHook hook,
+                                     const Options& options) {
+  DCHECK(!initialize_sandbox_ran_);
+  initialize_sandbox_ran_ = true;
+
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  const std::string process_type =
+      command_line->GetSwitchValueASCII(switches::kProcessType);
+
+  if (command_line->HasSwitch(switches::kNoSandbox))
+    return true;
+
+  VLOG(1) << "SandboxLinux::InitializeSandbox: process_type="
+      << process_type << " sandbox_type=" << sandbox_type;
+
+  // Only one thread is running, pre-initialize if not already done.
+  if (!pre_initialized_)
+    PreinitializeSandbox(sandbox_type);
+
+  // Attempt to limit the future size of the address space of the process.
+  int error = 0;
+  const bool limited_as = LimitAddressSpace(&error);
+  if (error) {
+    // Restore errno. Internally to |LimitAddressSpace|, the errno due to
+    // setrlimit may be lost.
+    errno = error;
+    PCHECK(limited_as);
+  }
+
+  if (hook)
+    CHECK(std::move(hook).Run(options));
+
+  return true;
+}
+
+bool SandboxLinux::LimitAddressSpace(int* error) {
+#if !defined(ADDRESS_SANITIZER) && !defined(MEMORY_SANITIZER) && \
+    !defined(THREAD_SANITIZER) && !defined(LEAK_SANITIZER)
+  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+  if (SandboxTypeFromCommandLine(*command_line) == sandbox::mojom::Sandbox::kNoSandbox) {
+    return false;
+  }
+
+  // Unfortunately, it does not appear possible to set RLIMIT_AS such that it
+  // will both (a) be high enough to support V8's and WebAssembly's address
+  // space requirements while also (b) being low enough to mitigate exploits
+  // using integer overflows that require large allocations, heap spray, or
+  // other memory-hungry attack modes.
+
+  *error = sandbox::ResourceLimits::Lower(
+      RLIMIT_DATA, static_cast<rlim_t>(sandbox::kDataSizeLimit));
+
+  // Cache the resource limit before turning on the sandbox.
+  base::SysInfo::AmountOfVirtualMemory();
+  base::SysInfo::MaxSharedMemorySize();
+
+  return *error == 0;
+#else
+  base::SysInfo::AmountOfVirtualMemory();
+  return false;
+#endif  // !defined(ADDRESS_SANITIZER) && !defined(MEMORY_SANITIZER) &&
+        // !defined(THREAD_SANITIZER) && !defined(LEAK_SANITIZER)
+}
+
+}  // namespace policy
+}  // namespace sandbox
