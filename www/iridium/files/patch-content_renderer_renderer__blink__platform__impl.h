--- content/renderer/renderer_blink_platform_impl.h.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/renderer/renderer_blink_platform_impl.h	2017-12-24 15:04:12.309104000 +0100
@@ -286,7 +286,7 @@
   class FileUtilities;
   std::unique_ptr<FileUtilities> file_utilities_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   class SandboxSupport;
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
