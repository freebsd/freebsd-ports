--- chrome/browser/download/download_shelf_context_menu.cc.orig	2020-03-16 18:39:43 UTC
+++ chrome/browser/download/download_shelf_context_menu.cc
@@ -147,7 +147,7 @@ base::string16 DownloadShelfContextMenu::GetLabelForCo
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
