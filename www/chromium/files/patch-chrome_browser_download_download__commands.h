--- chrome/browser/download/download_commands.h.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/download/download_commands.h
@@ -54,7 +54,7 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC) || defined(OS_FUCHSIA)
+    defined(OS_MAC) || defined(OS_FUCHSIA) || defined(OS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   Browser* GetBrowser() const;
