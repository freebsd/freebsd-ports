--- chrome/browser/chrome_browser_interface_binders.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -109,7 +109,7 @@
 #include "chrome/browser/ui/webui/new_tab_page/new_tab_page_ui.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
@@ -532,7 +532,7 @@ void PopulateChromeWebUIFrameBinders(
       media_app_ui::mojom::PageHandlerFactory, chromeos::MediaAppUI>(map);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
