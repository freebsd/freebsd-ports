--- content/renderer/renderer_blink_platform_impl.cc.orig	2023-11-22 14:00:11 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -113,7 +113,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -181,13 +181,13 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       sudden_termination_disables_(0),
       is_locked_to_site_(false),
       main_thread_scheduler_(main_thread_scheduler) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader;
 #endif
 
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -196,7 +196,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (sandboxEnabled()) {
 #if BUILDFLAG(IS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -254,7 +254,7 @@ void RendererBlinkPlatformImpl::SetThreadType(base::Pl
 #endif
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
