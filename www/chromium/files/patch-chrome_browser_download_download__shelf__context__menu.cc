--- chrome/browser/download/download_shelf_context_menu.cc.orig	2020-07-07 21:58:13 UTC
+++ chrome/browser/download/download_shelf_context_menu.cc
@@ -149,7 +149,7 @@ base::string16 DownloadShelfContextMenu::GetLabelForCo
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
