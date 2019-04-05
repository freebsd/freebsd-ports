--- chrome/browser/download/download_item_model.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/download/download_item_model.cc
@@ -555,7 +555,7 @@ bool DownloadItemModel::IsCommandChecked(
       return download_->GetOpenWhenComplete() ||
              download_crx_util::IsExtensionDownload(*download_);
     case DownloadCommands::ALWAYS_OPEN_TYPE:
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
         return prefs->ShouldOpenPdfInSystemReader();
@@ -592,7 +592,7 @@ void DownloadItemModel::ExecuteCommand(DownloadCommand
       bool is_checked = IsCommandChecked(download_commands,
                                          DownloadCommands::ALWAYS_OPEN_TYPE);
       DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         prefs->SetShouldOpenPdfInSystemReader(!is_checked);
         SetShouldPreferOpeningInBrowser(is_checked);
