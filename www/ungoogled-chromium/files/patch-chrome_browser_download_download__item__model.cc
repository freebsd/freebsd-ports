--- chrome/browser/download/download_item_model.cc.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/download/download_item_model.cc
@@ -744,7 +744,7 @@ bool DownloadItemModel::IsCommandChecked(
              download_crx_util::IsExtensionDownload(*download_);
     case DownloadCommands::ALWAYS_OPEN_TYPE:
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
         return prefs->ShouldOpenPdfInSystemReader();
@@ -790,7 +790,7 @@ void DownloadItemModel::ExecuteCommand(DownloadCommand
                                          DownloadCommands::ALWAYS_OPEN_TYPE);
       DownloadPrefs* prefs = DownloadPrefs::FromBrowserContext(profile());
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       if (download_commands->CanOpenPdfInSystemViewer()) {
         prefs->SetShouldOpenPdfInSystemReader(!is_checked);
         SetShouldPreferOpeningInBrowser(is_checked);
@@ -1065,7 +1065,7 @@ void DownloadItemModel::DetermineAndSetShouldPreferOpe
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (download_->GetOriginalMimeType() == "application/x-x509-user-cert") {
     SetShouldPreferOpeningInBrowser(true);
     return;
