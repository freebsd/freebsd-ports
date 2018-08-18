--- chrome/browser/download/download_commands.h.orig	2017-09-05 21:05:12.000000000 +0200
+++ chrome/browser/download/download_commands.h	2017-09-06 18:02:40.537871000 +0200
@@ -42,7 +42,7 @@
   bool IsCommandVisible(Command command) const;
   void ExecuteCommand(Command command);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
 #endif
