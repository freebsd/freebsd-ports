--- content/utility/services.cc.orig	2026-10-18 13:29:39 UTC
+++ content/utility/services.cc
@@ -74,14 +74,14 @@
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/sandbox_type.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
 #include "services/shape_detection/public/mojom/shape_detection_service.mojom.h"  // nogncheck
 #include "services/shape_detection/shape_detection_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) &&
@@ -238,7 +238,7 @@ auto RunAudio(mojo::PendingReceiver<audio::mojom::Audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -261,7 +261,7 @@ auto RunAudio(mojo::PendingReceiver<audio::mojom::Audi
 }
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
 auto RunShapeDetectionService(
     mojo::PendingReceiver<shape_detection::mojom::ShapeDetectionService>
         receiver) {
@@ -429,7 +429,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunOnDeviceModel);
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
   services.Add(RunShapeDetectionService);
 #endif
 
