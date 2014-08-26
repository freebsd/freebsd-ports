--- ./chrome/renderer/printing/print_web_view_helper.h.orig	2014-08-20 21:02:13.000000000 +0200
+++ ./chrome/renderer/printing/print_web_view_helper.h	2014-08-22 15:06:25.000000000 +0200
@@ -201,7 +201,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          const gfx::Size& canvas_size,
                          blink::WebFrame* frame,
