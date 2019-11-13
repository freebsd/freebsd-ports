--- content/renderer/renderer_blink_platform_impl.cc.orig	2019-10-21 19:06:33 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -102,7 +102,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -183,7 +183,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
   if (RenderThreadImpl::current()) {
     io_runner_ = RenderThreadImpl::current()->GetIOTaskRunner();
     thread_safe_sender_ = RenderThreadImpl::current()->thread_safe_sender();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -193,7 +193,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (sandboxEnabled()) {
 #if defined(OS_MACOSX)
     std::unique_ptr<service_manager::Connector> sandbox_connector;
@@ -224,7 +224,7 @@ RendererBlinkPlatformImpl::~RendererBlinkPlatformImpl(
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // SandboxSupport contains a map of OutOfProcessFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -289,7 +289,7 @@ RendererBlinkPlatformImpl::CreateNetworkURLLoaderFacto
 
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
     render_thread->render_message_filter()->SetThreadPriority(
         thread_id, base::ThreadPriority::DISPLAY);
@@ -302,7 +302,7 @@ blink::BlameContext* RendererBlinkPlatformImpl::GetTop
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
