--- chrome/browser/download/chrome_download_manager_delegate.cc.orig	2022-10-01 07:40:07 UTC
+++ chrome/browser/download/chrome_download_manager_delegate.cc
@@ -1532,7 +1532,7 @@ void ChromeDownloadManagerDelegate::OnDownloadTargetDe
 bool ChromeDownloadManagerDelegate::IsOpenInBrowserPreferreredForFile(
     const base::FilePath& path) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (path.MatchesExtension(FILE_PATH_LITERAL(".pdf"))) {
     return !download_prefs_->ShouldOpenPdfInSystemReader();
   }
@@ -1598,7 +1598,7 @@ void ChromeDownloadManagerDelegate::CheckDownloadAllow
     content::CheckDownloadAllowedCallback check_download_allowed_cb) {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Don't download pdf if it is a file URL, as that might cause an infinite
   // download loop if Chrome is not the system pdf viewer.
   if (url.SchemeIsFile() && download_prefs_->ShouldOpenPdfInSystemReader()) {
@@ -1640,7 +1640,7 @@ std::unique_ptr<download::DownloadItemRenameHandler>
 ChromeDownloadManagerDelegate::GetRenameHandlerForDownload(
     download::DownloadItem* download_item) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return enterprise_connectors::FileSystemRenameHandler::CreateIfNeeded(
       download_item);
 #else
