--- chrome/browser/download/download_shelf_context_menu.cc.orig	2017-04-19 19:06:29 UTC
+++ chrome/browser/download/download_shelf_context_menu.cc
@@ -127,7 +127,7 @@ base::string16 DownloadShelfContextMenu:
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
