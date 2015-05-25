--- chrome/browser/download/download_shelf_context_menu.cc.orig	2015-05-13 18:23:03.000000000 -0400
+++ chrome/browser/download/download_shelf_context_menu.cc	2015-05-20 09:21:47.075399000 -0400
@@ -143,7 +143,7 @@
                    : IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
         }
-#elif defined(OS_MACOSX) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         if (can_open_pdf_in_system_viewer) {
           id = IDS_DOWNLOAD_MENU_PLATFORM_OPEN_ALWAYS;
           break;
