--- content/renderer/renderer_blink_platform_impl.h.orig	2017-06-05 19:03:07 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -258,7 +258,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   class FileUtilities;
   std::unique_ptr<FileUtilities> file_utilities_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
