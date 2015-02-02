--- chrome/browser/download/download_shelf_context_menu.h.orig	2015-01-24 22:48:53 UTC
+++ chrome/browser/download/download_shelf_context_menu.h
@@ -75,7 +75,7 @@
 
   int GetAlwaysOpenStringId() const;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_MACOSX) && !defined(OS_IOS))
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
