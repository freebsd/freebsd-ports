--- content/utility/utility_main.cc.orig	2024-08-26 14:40:28 UTC
+++ content/utility/utility_main.cc
@@ -36,17 +36,21 @@
 #include "services/screen_ai/buildflags/buildflags.h"
 #include "services/tracing/public/cpp/trace_startup.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/file_descriptor_store.h"
 #include "base/files/file_util.h"
 #include "base/pickle.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/common/gpu_pre_sandbox_hook_linux.h"
+#endif
 #include "content/public/common/content_descriptor_keys.h"
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
 #include "gpu/config/gpu_info_collector.h"
 #include "media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 // gn check is not smart enough to realize that this include only applies to
@@ -58,10 +62,15 @@
 #endif
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "content/common/gpu_pre_sandbox_hook_bsd.h"
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "chromeos/ash/components/assistant/buildflags.h"
 #include "chromeos/ash/services/ime/ime_sandbox_hook.h"
@@ -73,7 +82,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if (BUILDFLAG(ENABLE_SCREEN_AI_SERVICE) && \
-     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)))
+     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)))
 #include "services/screen_ai/public/cpp/utilities.h"  // nogncheck
 #include "services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h"  // nogncheck
 #endif
@@ -101,7 +110,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::vector<std::string> GetNetworkContextsParentDirectories() {
   base::MemoryMappedFile::Region region;
   base::ScopedFD read_pipe_fd = base::FileDescriptorStore::GetInstance().TakeFD(
@@ -128,9 +137,10 @@ std::vector<std::string> GetNetworkContextsParentDirec
   return dirs;
 }
 
+#if !BUILDFLAG(IS_BSD)
 bool ShouldUseAmdGpuPolicy(sandbox::mojom::Sandbox sandbox_type) {
   const bool obtain_gpu_info =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
       sandbox_type == sandbox::mojom::Sandbox::kHardwareVideoEncoding;
@@ -145,6 +155,7 @@ bool ShouldUseAmdGpuPolicy(sandbox::mojom::Sandbox san
 
   return false;
 }
+#endif
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN)
@@ -242,7 +253,8 @@ int UtilityMain(MainFunctionParams parameters) {
     CHECK(on_device_model::OnDeviceModelService::PreSandboxInit());
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   // Thread type delegate of the process should be registered before first
   // thread type change in ChildProcess constructor. It also needs to be
   // registered before the process has multiple threads, which may race with
@@ -254,7 +266,7 @@ int UtilityMain(MainFunctionParams parameters) {
   }
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
@@ -292,7 +304,7 @@ int UtilityMain(MainFunctionParams parameters) {
                              screen_ai::GetBinaryPathSwitch()));
       break;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     case sandbox::mojom::Sandbox::kHardwareVideoDecoding:
       pre_sandbox_hook =
           base::BindOnce(&media::HardwareVideoDecodingPreSandboxHook);
@@ -319,6 +331,7 @@ int UtilityMain(MainFunctionParams parameters) {
     default:
       break;
   }
+#if !BUILDFLAG(IS_BSD)
   if (!sandbox::policy::IsUnsandboxedSandboxType(sandbox_type) &&
       (parameters.zygote_child || !pre_sandbox_hook.is_null())) {
     sandbox_options.use_amd_specific_policies =
@@ -326,6 +339,11 @@ int UtilityMain(MainFunctionParams parameters) {
     sandbox::policy::Sandbox::Initialize(
         sandbox_type, std::move(pre_sandbox_hook), sandbox_options);
   }
+#else
+  sandbox::policy::Sandbox::Initialize(
+      sandbox_type, std::move(pre_sandbox_hook),
+      sandbox::policy::SandboxLinux::Options());
+#endif
 
   // Start the HangWatcher now that the sandbox is engaged, if it hasn't
   // already been started.
