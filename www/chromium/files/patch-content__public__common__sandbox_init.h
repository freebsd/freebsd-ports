--- content/public/common/sandbox_init.h.orig	2012-06-25 21:27:29.628231368 +0300
+++ content/public/common/sandbox_init.h	2012-06-25 21:27:46.571430448 +0300
@@ -70,7 +70,7 @@
 CONTENT_EXPORT bool InitializeSandbox(int sandbox_type,
                                       const FilePath& allowed_path);
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
 CONTENT_EXPORT void InitializeSandbox();
 
