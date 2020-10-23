--- content/renderer/renderer_blink_platform_impl.cc.orig	2020-09-08 19:14:05 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -97,7 +97,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -169,7 +169,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -179,7 +179,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (sandboxEnabled()) {
 #if defined(OS_MACOSX)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -261,7 +261,7 @@ RendererBlinkPlatformImpl::CreateNetworkURLLoaderFacto
 
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
     render_thread->render_message_filter()->SetThreadPriority(
         thread_id, base::ThreadPriority::DISPLAY);
@@ -274,7 +274,7 @@ blink::BlameContext* RendererBlinkPlatformImpl::GetTop
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
