--- chrome/renderer/printing/print_web_view_helper.h.orig	2013-07-15 18:53:40.000000000 +0300
+++ chrome/renderer/printing/print_web_view_helper.h	2013-07-15 18:54:07.000000000 +0300
@@ -213,7 +213,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          const gfx::Size& canvas_size,
                          WebKit::WebFrame* frame,
