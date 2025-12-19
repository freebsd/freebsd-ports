--- src/3rdparty/chromium/content/utility/services.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/content/utility/services.cc
@@ -78,7 +78,7 @@ extern sandbox::TargetServices* g_utility_target_servi
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/services/mojo_video_encode_accelerator_provider_factory.h"
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
@@ -106,7 +106,7 @@ extern sandbox::TargetServices* g_utility_target_servi
 #endif  // BUILDFLAG(IS_CHROMEOS) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 #include "content/common/features.h"
 #include "media/mojo/services/stable_video_decoder_factory_process_service.h"  // nogncheck
@@ -242,7 +242,7 @@ auto RunAudio(mojo::PendingReceiver<audio::mojom::Audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -388,7 +388,7 @@ auto RunOOPArcVideoAcceleratorFactoryService(
 #endif  // BUILDFLAG(IS_CHROMEOS) && \
         // (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 auto RunStableVideoDecoderFactoryProcessService(
     mojo::PendingReceiver<
@@ -399,7 +399,7 @@ auto RunStableVideoDecoderFactoryProcessService(
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
         // (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 auto RunVideoEncodeAcceleratorProviderFactory(
     mojo::PendingReceiver<media::mojom::VideoEncodeAcceleratorProviderFactory>
         receiver) {
@@ -422,7 +422,7 @@ void RegisterIOThreadServices(mojo::ServiceFactory& se
   // loop of type IO that can get notified when pipes have data.
   services.Add(RunNetworkService);
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
   services.Add(RunStableVideoDecoderFactoryProcessService);
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) &&
@@ -477,7 +477,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
 #endif  // BUILDFLAG(IS_CHROMEOS) && \
         // (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   services.Add(RunVideoEncodeAcceleratorProviderFactory);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
