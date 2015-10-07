--- chrome/browser/download/download_commands.cc.orig	2015-07-16 07:26:09.936296000 -0400
+++ chrome/browser/download/download_commands.cc	2015-07-16 07:27:35.099271000 -0400
@@ -100,7 +100,7 @@
              download_crx_util::IsExtensionDownload(*download_item_);
     case ALWAYS_OPEN_TYPE:
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    (defined(OS_MACOSX) && !defined(OS_IOS))
+    (defined(OS_MACOSX) && !defined(OS_IOS)) || defined(OS_BSD)
       if (CanOpenPdfInSystemViewer()) {
         DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(
             download_item_->GetBrowserContext());
@@ -144,7 +144,7 @@
       DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(
           download_item_->GetBrowserContext());
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    (defined(OS_MACOSX) && !defined(OS_IOS))
+    (defined(OS_MACOSX) && !defined(OS_IOS)) || defined(OS_BSD)
       if (CanOpenPdfInSystemViewer()) {
         prefs->SetShouldOpenPdfInSystemReader(!is_checked);
         DownloadItemModel(download_item_)
@@ -218,7 +218,7 @@
   return browser_displayer.browser();
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 bool DownloadCommands::IsDownloadPdf() const {
   base::FilePath path = download_item_->GetTargetFilePath();
   return path.MatchesExtension(FILE_PATH_LITERAL(".pdf"));
@@ -235,7 +235,7 @@
   return IsDownloadPdf() &&
          (IsAdobeReaderDefaultPDFViewer() ? is_adobe_pdf_reader_up_to_date
                                           : true);
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return IsDownloadPdf();
 #endif
 }
