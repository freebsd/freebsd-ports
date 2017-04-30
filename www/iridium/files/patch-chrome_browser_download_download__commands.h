--- chrome/browser/download/download_commands.h.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/download/download_commands.h
@@ -43,7 +43,8 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    (defined(OS_MACOSX) && !defined(OS_IOS))
+    defined(OS_BSD) || (defined(OS_MACOSX) && \
+    !defined(OS_IOS))
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
 #endif
