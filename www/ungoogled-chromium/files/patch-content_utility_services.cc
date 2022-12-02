--- content/utility/services.cc.orig	2022-12-02 17:56:32 UTC
+++ content/utility/services.cc
@@ -66,7 +66,7 @@
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/sandbox_type.h"
@@ -88,7 +88,7 @@ extern sandbox::TargetServices* g_utility_target_servi
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 #include "media/mojo/services/stable_video_decoder_factory_service.h"  // nogncheck
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&
@@ -211,7 +211,7 @@ auto RunAudio(mojo::PendingReceiver<audio::mojom::Audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -326,7 +326,7 @@ auto RunOOPArcVideoAcceleratorFactoryService(
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 auto RunStableVideoDecoderFactoryService(
     mojo::PendingReceiver<media::stable::mojom::StableVideoDecoderFactory>
@@ -380,7 +380,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
   services.Add(RunStableVideoDecoderFactoryService);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&
