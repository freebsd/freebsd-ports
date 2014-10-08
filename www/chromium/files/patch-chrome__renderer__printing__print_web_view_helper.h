--- chrome/renderer/printing/print_web_view_helper.h.orig	2014-10-02 17:39:46 UTC
+++ chrome/renderer/printing/print_web_view_helper.h
@@ -207,7 +207,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          const gfx::Size& canvas_size,
                          blink::WebFrame* frame,
