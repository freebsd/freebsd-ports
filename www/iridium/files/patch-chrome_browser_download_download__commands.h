--- chrome/browser/download/download_commands.h.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/download/download_commands.h
@@ -62,7 +62,7 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   Browser* GetBrowser() const;
