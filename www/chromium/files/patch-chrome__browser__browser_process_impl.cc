--- ./chrome/browser/browser_process_impl.cc.orig	2014-08-20 21:02:13.000000000 +0200
+++ ./chrome/browser/browser_process_impl.cc	2014-08-22 15:06:24.000000000 +0200
@@ -248,7 +248,7 @@
 
   ExtensionRendererState::GetInstance()->Shutdown();
 
-#if !defined(OS_ANDROID) && !defined(OS_IOS)
+#if !defined(OS_ANDROID) && !defined(OS_IOS) && !defined(OS_BSD)
   media_file_system_registry_.reset();
   // Remove the global instance of the Storage Monitor now. Otherwise the
   // FILE thread would be gone when we try to release it in the dtor and
