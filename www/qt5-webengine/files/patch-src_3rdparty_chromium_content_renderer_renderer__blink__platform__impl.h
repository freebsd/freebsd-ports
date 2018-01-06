--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h
@@ -256,7 +256,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   class FileUtilities;
   std::unique_ptr<FileUtilities> file_utilities_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
