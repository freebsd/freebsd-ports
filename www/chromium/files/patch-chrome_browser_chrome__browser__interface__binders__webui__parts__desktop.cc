--- chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc
@@ -145,7 +145,7 @@
 #include "ui/webui/resources/js/batch_upload_promo/batch_upload_promo.mojom.h"
 #include "ui/webui/resources/js/browser_command/browser_command.mojom.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_home/app_home.mojom.h"
 #include "chrome/browser/ui/webui/app_home/app_home_ui.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
@@ -321,7 +321,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         HistoryClustersSidePanelUI, NewTabPageUI, BookmarksSidePanelUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<whats_new::mojom::PageHandlerFactory,
                                          WhatsNewUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -331,7 +331,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
 
   RegisterWebUIControllerInterfaceBinder<
       browser_command::mojom::CommandHandlerFactory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       WhatsNewUI,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       NewTabPageUI>(map);
@@ -518,7 +518,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         DrivePickerUntrustedHostUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 
@@ -544,7 +544,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
                                          webapps::AppHomeUI>(map);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<updater_ui::mojom::PageHandlerFactory,
                                          UpdaterUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
