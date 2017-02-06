--- chrome/browser/download/download_commands.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/download/download_commands.cc
@@ -217,7 +217,7 @@ bool DownloadCommands::IsCommandChecked(
       return download_item_->GetOpenWhenComplete() ||
              download_crx_util::IsExtensionDownload(*download_item_);
     case ALWAYS_OPEN_TYPE:
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       if (CanOpenPdfInSystemViewer()) {
         DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(
             download_item_->GetBrowserContext());
@@ -261,7 +261,7 @@ void DownloadCommands::ExecuteCommand(Co
       bool is_checked = IsCommandChecked(ALWAYS_OPEN_TYPE);
       DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(
           download_item_->GetBrowserContext());
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       if (CanOpenPdfInSystemViewer()) {
         prefs->SetShouldOpenPdfInSystemReader(!is_checked);
         DownloadItemModel(download_item_)
@@ -374,7 +374,7 @@ Browser* DownloadCommands::GetBrowser() 
   return browser_displayer.browser();
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 bool DownloadCommands::IsDownloadPdf() const {
   base::FilePath path = download_item_->GetTargetFilePath();
   return path.MatchesExtension(FILE_PATH_LITERAL(".pdf"));
@@ -391,7 +391,7 @@ bool DownloadCommands::CanOpenPdfInSyste
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
