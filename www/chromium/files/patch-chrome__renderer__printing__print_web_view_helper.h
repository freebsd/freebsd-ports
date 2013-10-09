--- chrome/renderer/printing/print_web_view_helper.h.orig	2013-08-30 06:47:03.000000000 +0300
+++ chrome/renderer/printing/print_web_view_helper.h	2013-09-03 21:39:51.232633592 +0300
@@ -231,7 +231,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          const gfx::Size& canvas_size,
                          WebKit::WebFrame* frame,
