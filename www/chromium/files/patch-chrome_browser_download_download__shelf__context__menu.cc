--- chrome/browser/download/download_shelf_context_menu.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/download/download_shelf_context_menu.cc
@@ -146,7 +146,7 @@ base::string16 DownloadShelfContextMenu::GetLabelForCo
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
