--- chrome/browser/download/download_commands.cc.orig	2019-04-30 22:22:33 UTC
+++ chrome/browser/download/download_commands.cc
@@ -159,7 +159,7 @@ Browser* DownloadCommands::GetBrowser() const {
   return browser_displayer.browser();
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 bool DownloadCommands::IsDownloadPdf() const {
   base::FilePath path = model_->GetTargetFilePath();
   return path.MatchesExtension(FILE_PATH_LITERAL(".pdf"));
@@ -176,7 +176,7 @@ bool DownloadCommands::CanOpenPdfInSystemViewer() cons
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
