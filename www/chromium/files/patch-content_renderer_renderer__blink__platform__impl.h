--- content/renderer/renderer_blink_platform_impl.h.orig	2016-05-11 19:02:22 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -250,7 +250,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   class MimeRegistry;
   scoped_ptr<MimeRegistry> mime_registry_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   scoped_ptr<SandboxSupport> sandbox_support_;
 #endif
