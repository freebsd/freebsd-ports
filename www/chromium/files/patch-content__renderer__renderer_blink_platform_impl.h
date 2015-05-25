--- content/renderer/renderer_blink_platform_impl.h.orig	2015-05-21 10:17:35.674995000 -0400
+++ content/renderer/renderer_blink_platform_impl.h	2015-05-21 10:17:56.809792000 -0400
@@ -218,7 +218,7 @@
   class MimeRegistry;
   scoped_ptr<MimeRegistry> mime_registry_;
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   class SandboxSupport;
   scoped_ptr<SandboxSupport> sandbox_support_;
 #endif
