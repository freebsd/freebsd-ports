--- content/renderer/renderer_blink_platform_impl.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/renderer/renderer_blink_platform_impl.cc	2017-12-31 05:15:48.537395000 +0100
@@ -124,7 +124,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -225,7 +225,7 @@
   scoped_refptr<mojom::ThreadSafeFileUtilitiesHostPtr> file_utilities_host_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -267,7 +267,7 @@
       default_task_runner_(renderer_scheduler->DefaultTaskRunner()),
       web_scrollbar_behavior_(new WebScrollbarBehaviorImpl),
       renderer_scheduler_(renderer_scheduler) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -316,7 +316,7 @@
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // SandboxSupport contains a map of WebFallbackFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -417,7 +417,7 @@
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -610,7 +610,7 @@
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::GetFallbackFontForCharacter(
     blink::WebUChar32 character,
