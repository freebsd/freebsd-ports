--- content/renderer/renderer_blink_platform_impl.cc.orig	2015-05-13 18:35:46.000000000 -0400
+++ content/renderer/renderer_blink_platform_impl.cc        2015-05-20 15:52:34.484662000 -0400
@@ -99,7 +99,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -189,7 +189,7 @@
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -216,7 +216,7 @@
   std::map<int32_t, blink::WebFallbackFont> unicode_font_families_;
 #endif
 };
-#endif  // !defined(OS_ANDROID) && !defined(OS_WIN)
+#endif  // !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
 
 //------------------------------------------------------------------------------
 
@@ -232,7 +232,7 @@
       plugin_refresh_allowed_(true),
       default_task_runner_(renderer_scheduler->DefaultTaskRunner()),
       web_scrollbar_behavior_(new WebScrollbarBehaviorImpl) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -289,7 +289,7 @@
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::sandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -557,7 +557,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::getFallbackFontForCharacter(
     blink::WebUChar32 character,
