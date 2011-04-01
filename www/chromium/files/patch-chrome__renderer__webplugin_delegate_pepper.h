--- ./chrome/renderer/webplugin_delegate_pepper.h.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/webplugin_delegate_pepper.h	2010-12-20 20:15:08.000000000 +0100
@@ -308,7 +308,7 @@
   // variable to hold on to the pixels.
   SkBitmap last_printed_page_;
 #endif   // defined(OS_MACOSX)
-#if defined (OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // On Linux, we always send all pages from the renderer to the browser.
   // So, if the plugin supports printPagesAsPDF we print the entire output
   // in one shot in the first call to PrintPage.
@@ -319,7 +319,7 @@
   // Specifies whether we have already output all pages. This is used to ignore
   // subsequent PrintPage requests.
   bool pdf_output_done_;
-#endif   // defined(OS_LINUX)
+#endif   // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(ENABLE_GPU)
   // The command buffer used to issue commands to the nested GPU plugin.
