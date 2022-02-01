--- content/renderer/renderer_blink_platform_impl.cc.orig	2021-12-31 00:57:32 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -108,7 +108,7 @@
 
 #if defined(OS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -177,7 +177,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       main_thread_scheduler_(main_thread_scheduler) {
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -187,7 +187,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   if (sandboxEnabled()) {
 #if defined(OS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -261,7 +261,7 @@ RendererBlinkPlatformImpl::WrapSharedURLLoaderFactory(
       /*terminate_sync_load_event=*/nullptr);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
@@ -276,7 +276,7 @@ blink::BlameContext* RendererBlinkPlatformImpl::GetTop
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
