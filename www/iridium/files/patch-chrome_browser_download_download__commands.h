--- chrome/browser/download/download_commands.h.orig	2024-02-04 14:46:08 UTC
+++ chrome/browser/download/download_commands.h
@@ -63,7 +63,7 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   Browser* GetBrowser() const;
