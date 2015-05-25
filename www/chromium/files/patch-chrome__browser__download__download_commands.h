--- chrome/browser/download/download_commands.h.orig	2015-05-21 11:39:00.521239000 -0400
+++ chrome/browser/download/download_commands.h	2015-05-21 11:39:40.015902000 -0400
@@ -41,7 +41,8 @@
   void ExecuteCommand(Command command);
 
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    (defined(OS_MACOSX) && !defined(OS_IOS))
+    defined(OS_BSD) || (defined(OS_MACOSX) && \
+    !defined(OS_IOS))
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
 #endif
