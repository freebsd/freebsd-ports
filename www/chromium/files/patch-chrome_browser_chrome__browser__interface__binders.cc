--- chrome/browser/chrome_browser_interface_binders.cc.orig	2020-07-07 21:58:13 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -113,7 +113,7 @@
 #include "media/mojo/mojom/speech_recognition_service.mojom.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
@@ -551,7 +551,7 @@ void PopulateChromeWebUIFrameBinders(
       media_app_ui::mojom::PageHandlerFactory, chromeos::MediaAppUI>(map);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
