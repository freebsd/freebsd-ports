--- content/renderer/renderer_blink_platform_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -108,7 +108,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -177,7 +177,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       main_thread_scheduler_(main_thread_scheduler) {
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -187,7 +187,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (sandboxEnabled()) {
 #if BUILDFLAG(IS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -261,7 +261,8 @@ RendererBlinkPlatformImpl::WrapSharedURLLoaderFactory(
       /*terminate_sync_load_event=*/nullptr);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// pledge
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
@@ -276,7 +277,7 @@ blink::BlameContext* RendererBlinkPlatformImpl::GetTop
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
