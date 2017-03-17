--- content/renderer/renderer_blink_platform_impl.h.orig	2017-03-09 20:04:32 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -252,7 +252,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   class FileUtilities;
   std::unique_ptr<FileUtilities> file_utilities_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
