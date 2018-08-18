--- content/renderer/renderer_blink_platform_impl.cc.orig	2018-06-13 00:10:17.000000000 +0200
+++ content/renderer/renderer_blink_platform_impl.cc	2018-07-19 13:00:02.053483000 +0200
@@ -136,7 +136,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -249,7 +249,7 @@
   scoped_refptr<mojom::ThreadSafeFileUtilitiesHostPtr> file_utilities_host_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -293,7 +293,7 @@
       default_task_runner_(main_thread_scheduler->DefaultTaskRunner()),
       web_scrollbar_behavior_(new WebScrollbarBehaviorImpl),
       main_thread_scheduler_(main_thread_scheduler) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -341,7 +341,7 @@
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // SandboxSupport contains a map of WebFallbackFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -449,7 +449,7 @@
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -657,7 +657,7 @@
   return content::LoadFont(src_font, out, font_id);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::GetFallbackFontForCharacter(
     blink::WebUChar32 character,
