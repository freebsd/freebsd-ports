--- chrome/renderer/printing/print_web_view_helper.h.orig	2014-10-10 09:15:30 UTC
+++ chrome/renderer/printing/print_web_view_helper.h
@@ -211,7 +211,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          blink::WebFrame* frame,
                          PdfMetafileSkia* metafile);
