--- chrome/browser/download/chrome_download_manager_delegate.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/download/chrome_download_manager_delegate.cc
@@ -1540,7 +1540,7 @@ void ChromeDownloadManagerDelegate::OnDownloadTargetDe
         target_info->is_filetype_handled_safely)
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (item->GetOriginalMimeType() == "application/x-x509-user-cert")
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 #endif
@@ -1609,7 +1609,7 @@ void ChromeDownloadManagerDelegate::OnDownloadTargetDe
 bool ChromeDownloadManagerDelegate::IsOpenInBrowserPreferreredForFile(
     const base::FilePath& path) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (path.MatchesExtension(FILE_PATH_LITERAL(".pdf"))) {
     return !download_prefs_->ShouldOpenPdfInSystemReader();
   }
@@ -1717,7 +1717,7 @@ void ChromeDownloadManagerDelegate::CheckDownloadAllow
     content::CheckDownloadAllowedCallback check_download_allowed_cb) {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Don't download pdf if it is a file URL, as that might cause an infinite
   // download loop if Chrome is not the system pdf viewer.
   if (url.SchemeIsFile() && download_prefs_->ShouldOpenPdfInSystemReader()) {
@@ -1759,7 +1759,7 @@ std::unique_ptr<download::DownloadItemRenameHandler>
 ChromeDownloadManagerDelegate::GetRenameHandlerForDownload(
     download::DownloadItem* download_item) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return enterprise_connectors::FileSystemRenameHandler::CreateIfNeeded(
       download_item);
 #else
@@ -1775,7 +1775,7 @@ void ChromeDownloadManagerDelegate::CheckSavePackageAl
   DCHECK(download_item->IsSavePackageDownload());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   absl::optional<enterprise_connectors::AnalysisSettings> settings =
       safe_browsing::DeepScanningRequest::ShouldUploadBinary(download_item);
 
