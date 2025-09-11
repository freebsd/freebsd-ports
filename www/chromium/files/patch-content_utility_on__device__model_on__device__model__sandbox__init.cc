--- content/utility/on_device_model/on_device_model_sandbox_init.cc.orig	2025-09-06 10:01:20 UTC
+++ content/utility/on_device_model/on_device_model_sandbox_init.cc
@@ -17,16 +17,20 @@
 #include "services/on_device_model/ml/gpu_blocklist.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <errno.h>
 
 #include "content/common/gpu_pre_sandbox_hook_linux.h"
 #include "gpu/config/gpu_info_collector.h"  // nogncheck
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
+#endif
 
 #if !BUILDFLAG(IS_FUCHSIA) && \
-    !(BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_CAST_RECEIVER))
+    !((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_CAST_RECEIVER))
 #include "base/feature_list.h"
 #include "third_party/dawn/include/dawn/dawn_proc.h"          // nogncheck
 #include "third_party/dawn/include/dawn/native/DawnNative.h"  // nogncheck
@@ -37,7 +41,7 @@ namespace on_device_model {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr uint32_t kVendorIdAMD = 0x1002;
 constexpr uint32_t kVendorIdIntel = 0x8086;
 constexpr uint32_t kVendorIdNVIDIA = 0x10DE;
@@ -66,13 +70,13 @@ void UpdateSandboxOptionsForGpu(
 #endif
 
 #if !BUILDFLAG(IS_FUCHSIA) && \
-    !(BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_CAST_RECEIVER))
+    !((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_CAST_RECEIVER))
 // If this feature is enabled, a WebGPU device is created for each valid
 // adapter. This makes sure any relevant drivers or other libs are loaded before
 // enabling the sandbox.
 BASE_FEATURE(kOnDeviceModelWarmDrivers,
              "OnDeviceModelWarmDrivers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -101,7 +105,7 @@ bool PreSandboxInit() {
 #endif
 
 #if !BUILDFLAG(IS_FUCHSIA) && \
-    !(BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_CAST_RECEIVER))
+    !((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_CAST_RECEIVER))
   if (base::FeatureList::IsEnabled(kOnDeviceModelWarmDrivers)
 #if defined(ENABLE_ML_INTERNAL)
       && !ml::IsGpuBlocked(ml::ChromeML::Get()->api(), /*log_histogram=*/false)
@@ -141,7 +145,7 @@ bool PreSandboxInit() {
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void AddSandboxLinuxOptions(sandbox::policy::SandboxLinux::Options& options) {
   // Make sure any necessary vendor-specific options are set.
   gpu::GPUInfo info;
@@ -153,6 +157,7 @@ void AddSandboxLinuxOptions(sandbox::policy::SandboxLi
 }
 
 bool PreSandboxHook(sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   std::vector<sandbox::syscall_broker::BrokerFilePermission> file_permissions =
       content::FilePermissionsForGpu(options);
   file_permissions.push_back(
@@ -161,6 +166,7 @@ bool PreSandboxHook(sandbox::policy::SandboxLinux::Opt
 
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       content::CommandSetForGPU(options), file_permissions, options);
+#endif
 
   if (!content::LoadLibrariesForGpu(options)) {
     return false;
