--- content/renderer/renderer_blink_platform_impl.cc.orig	2017-06-05 19:03:07 UTC
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -112,7 +112,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -206,7 +206,7 @@ class RendererBlinkPlatformImpl::FileUtilities : publi
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -251,7 +251,7 @@ RendererBlinkPlatformImpl::RendererBlinkPlatformImpl(
       web_scrollbar_behavior_(new WebScrollbarBehaviorImpl),
       renderer_scheduler_(renderer_scheduler),
       blink_interface_provider_(new BlinkInterfaceProviderImpl(connector)) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -294,7 +294,7 @@ RendererBlinkPlatformImpl::~RendererBlinkPlatformImpl(
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   // SandboxSupport contains a map of WebFontFamily objects, which hold
   // WebCStrings, which become invalidated when blink is shut down. Hence, we
   // need to clear that map now, just before blink::shutdown() is called.
@@ -358,7 +358,7 @@ blink::WebFileUtilities* RendererBlinkPlatformImpl::Ge
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -565,7 +565,7 @@ bool RendererBlinkPlatformImpl::SandboxSupport::LoadFo
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::GetFallbackFontForCharacter(
     blink::WebUChar32 character,
