--- components/printing/renderer/print_web_view_helper.h.orig	2015-04-20 18:54:28.000000000 +0200
+++ components/printing/renderer/print_web_view_helper.h	2015-04-20 18:55:05.000000000 +0200
@@ -246,7 +246,7 @@
   void FinishFramePrinting();
 
   // Prints the page listed in |params|.
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FREEBSD)
   void PrintPageInternal(const PrintMsg_PrintPage_Params& params,
                          blink::WebFrame* frame,
                          PdfMetafileSkia* metafile);
