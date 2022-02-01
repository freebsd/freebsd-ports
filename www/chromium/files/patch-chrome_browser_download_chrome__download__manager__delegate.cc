--- chrome/browser/download/chrome_download_manager_delegate.cc.orig	2021-12-31 00:57:22 UTC
+++ chrome/browser/download/chrome_download_manager_delegate.cc
@@ -1540,7 +1540,7 @@ void ChromeDownloadManagerDelegate::OnDownloadTargetDe
         target_info->is_filetype_handled_safely)
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     if (item->GetOriginalMimeType() == "application/x-x509-user-cert")
       DownloadItemModel(item).SetShouldPreferOpeningInBrowser(true);
 #endif
@@ -1608,7 +1608,7 @@ void ChromeDownloadManagerDelegate::OnDownloadTargetDe
 
 bool ChromeDownloadManagerDelegate::IsOpenInBrowserPreferreredForFile(
     const base::FilePath& path) {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   if (path.MatchesExtension(FILE_PATH_LITERAL(".pdf"))) {
     return !download_prefs_->ShouldOpenPdfInSystemReader();
@@ -1716,7 +1716,7 @@ void ChromeDownloadManagerDelegate::CheckDownloadAllow
     bool content_initiated,
     content::CheckDownloadAllowedCallback check_download_allowed_cb) {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   // Don't download pdf if it is a file URL, as that might cause an infinite
   // download loop if Chrome is not the system pdf viewer.
@@ -1758,7 +1758,7 @@ ChromeDownloadManagerDelegate::GetQuarantineConnection
 std::unique_ptr<download::DownloadItemRenameHandler>
 ChromeDownloadManagerDelegate::GetRenameHandlerForDownload(
     download::DownloadItem* download_item) {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   return enterprise_connectors::FileSystemRenameHandler::CreateIfNeeded(
       download_item);
@@ -1774,7 +1774,7 @@ void ChromeDownloadManagerDelegate::CheckSavePackageAl
   DCHECK(download_item);
   DCHECK(download_item->IsSavePackageDownload());
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_MAC)
   if (!base::FeatureList::IsEnabled(
           download::features::kAllowSavePackageScanning)) {
