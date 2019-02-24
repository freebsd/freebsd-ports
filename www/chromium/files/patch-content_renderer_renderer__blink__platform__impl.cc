--- content/renderer/renderer_blink_platform_impl.cc.orig	2019-01-30 02:18:00.000000000 +0100
+++ content/renderer/renderer_blink_platform_impl.cc	2019-02-07 00:24:24.998896000 +0100
@@ -193,7 +193,7 @@
 
 //------------------------------------------------------------------------------
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -223,7 +223,7 @@
   std::map<int32_t, blink::OutOfProcessFont> unicode_font_families_;
   sk_sp<font_service::FontLoader> font_loader_;
 };
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 //------------------------------------------------------------------------------
 
@@ -247,7 +247,7 @@
                      ->Clone();
     thread_safe_sender_ = RenderThreadImpl::current()->thread_safe_sender();
     blob_registry_.reset(new WebBlobRegistryImpl(thread_safe_sender_.get()));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     font_loader_ = sk_make_sp<font_service::FontLoader>(connector_.get());
     SkFontConfigInterface::SetGlobal(font_loader_);
 #endif
@@ -256,7 +256,7 @@
     connector_ = service_manager::Connector::Create(&request);
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
 #if defined(OS_MACOSX)
     sandbox_support_.reset(new WebSandboxSupportMac(connector_.get()));
@@ -285,7 +285,7 @@
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // SandboxSupport contains a map of OutOfProcessFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -366,7 +366,7 @@
 
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
     render_thread->render_message_filter()->SetThreadPriority(
         thread_id, base::ThreadPriority::DISPLAY);
@@ -379,7 +379,7 @@
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
@@ -560,7 +560,7 @@
 
 //------------------------------------------------------------------------------
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::GetFallbackFontForCharacter(
     blink::WebUChar32 character,
