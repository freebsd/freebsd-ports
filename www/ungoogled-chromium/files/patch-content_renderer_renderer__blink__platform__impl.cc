--- content/renderer/renderer_blink_platform_impl.cc.orig	2026-01-16 13:40:34 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -121,7 +121,7 @@
 #include "content/child/child_process_sandbox_support_impl_win.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/child/font_data/font_data_manager.h"
 #include "skia/ext/font_utils.h"
 #include "third_party/blink/public/web/win/web_font_rendering.h"
@@ -129,7 +129,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
@@ -205,13 +205,13 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       is_locked_to_site_(false),
       main_thread_scheduler_(main_thread_scheduler),
       next_frame_sink_id_(uint32_t{std::numeric_limits<int32_t>::max()} + 1) {
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
@@ -219,7 +219,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
     SkFontConfigInterface::SetGlobal(font_loader);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Create a FontDataManager if it's enabled, and if we're not in a
     // single-process environment. In single process, the SkFontMgr is already
     // installed by browser process code at this point.
@@ -233,7 +233,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandboxEnabled()) {
 #if BUILDFLAG(IS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -306,7 +306,7 @@ RendererBlinkPlatformImpl::GetWebUIBundledCodeCacheRes
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
