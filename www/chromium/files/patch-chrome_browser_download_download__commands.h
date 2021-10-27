--- chrome/browser/download/download_commands.h.orig	2021-09-24 04:25:58 UTC
+++ chrome/browser/download/download_commands.h
@@ -48,7 +48,7 @@ class DownloadCommands {
   bool IsCommandVisible(Command command) const;
   void ExecuteCommand(Command command);
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC) || defined(OS_FUCHSIA)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
