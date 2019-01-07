--- chrome/browser/download/download_commands.cc.orig	2018-12-03 21:16:39.000000000 +0100
+++ chrome/browser/download/download_commands.cc	2018-12-05 14:35:24.756358000 +0100
@@ -220,7 +220,7 @@
   return browser_displayer.browser();
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 bool DownloadCommands::IsDownloadPdf() const {
   base::FilePath path = model_->GetTargetFilePath();
   return path.MatchesExtension(FILE_PATH_LITERAL(".pdf"));
@@ -237,7 +237,7 @@
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
