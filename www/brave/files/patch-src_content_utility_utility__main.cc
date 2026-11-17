--- src/content/utility/utility_main.cc.orig	2026-10-18 18:43:23 UTC
+++ src/content/utility/utility_main.cc
@@ -44,22 +44,31 @@
 #include "services/tracing/public/cpp/trace_startup.h"
 #include "services/video_capture/public/mojom/video_capture_service.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/file_descriptor_store.h"
 #include "base/files/file_util.h"
 #include "base/pickle.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
+#if !BUILDFLAG(IS_BSD)
 #include "content/common/gpu_pre_sandbox_hook_linux.h"
+#endif
 #include "content/public/common/content_descriptor_keys.h"
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
 #include "media/gpu/buildflags.h"
 #include "media/media_buildflags.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 #include "services/screen_ai/buildflags/buildflags.h"
 #include "services/shape_detection/shape_detection_sandbox_hook.h"
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "content/common/gpu_pre_sandbox_hook_bsd.h"
+#endif
+
 #if BUILDFLAG(USE_LINUX_VIDEO_ACCELERATION)
 #include "gpu/config/gpu_info_collector.h"
 #include "media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h"
@@ -122,7 +131,7 @@ sandbox::TargetServices* g_utility_targe
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "components/on_device_translation/service/sandbox_hook.h"
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) &&  (BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS))
@@ -131,7 +140,7 @@ namespace content {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::vector<std::string> GetNetworkContextsParentDirectories() {
   base::MemoryMappedFile::Region region;
   base::ScopedFD read_pipe_fd = base::FileDescriptorStore::GetInstance().TakeFD(
@@ -296,7 +305,7 @@ int UtilityMain(MainFunctionParams param
     CHECK(on_device_model::PreSandboxInit());
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER) && BUILDFLAG(USE_VAAPI)
   // Regardless of the sandbox status, the VaapiWrapper needs to be initialized
@@ -311,7 +320,10 @@ int UtilityMain(MainFunctionParams param
   // thread type change in ChildProcess constructor. It also needs to be
   // registered before the process has multiple threads, which may race with
   // application of the sandbox.
+// XXX BSD
+#if !BUILDFLAG(IS_BSD) 
   SandboxedProcessThreadTypeHandler::Create();
+#endif
 
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
@@ -344,7 +356,7 @@ int UtilityMain(MainFunctionParams param
           base::BindOnce(&speech::SpeechRecognitionPreSandboxHook);
       break;
 #if BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
     case sandbox::mojom::Sandbox::kOnDeviceTranslation:
       pre_sandbox_hook = base::BindOnce(
           &on_device_translation::OnDeviceTranslationSandboxHook);
@@ -361,7 +373,7 @@ int UtilityMain(MainFunctionParams param
 #else
       NOTREACHED();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case sandbox::mojom::Sandbox::kShapeDetection:
       pre_sandbox_hook =
           base::BindOnce(&shape_detection::ShapeDetectionPreSandboxHook);
@@ -390,6 +402,7 @@ int UtilityMain(MainFunctionParams param
     default:
       break;
   }
+#if !BUILDFLAG(IS_BSD)
   if (!sandbox::policy::IsUnsandboxedSandboxType(sandbox_type) &&
       (parameters.zygote_child || !pre_sandbox_hook.is_null())) {
     sandbox_options.use_amd_specific_policies =
@@ -397,6 +410,11 @@ int UtilityMain(MainFunctionParams param
     sandbox::policy::Sandbox::Initialize(
         sandbox_type, std::move(pre_sandbox_hook), sandbox_options);
   }
+#else
+  sandbox::policy::Sandbox::Initialize(
+      sandbox_type, std::move(pre_sandbox_hook),
+      sandbox::policy::SandboxLinux::Options());
+#endif
 
   // Startup tracing creates a tracing thread, which is incompatible on
   // platforms that require single-threaded sandbox initialization. In these
