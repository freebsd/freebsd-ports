--- chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc.orig	2025-10-30 15:44:36 UTC
+++ chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc
@@ -110,7 +110,7 @@
 #include "ui/webui/resources/js/browser_command/browser_command.mojom.h"
 #include "ui/webui/resources/js/tracked_element/tracked_element.mojom.h"  // nogncheck crbug.com/1125897
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_home/app_home.mojom.h"
 #include "chrome/browser/ui/webui/app_home/app_home_ui.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
@@ -331,14 +331,14 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
         HistoryClustersSidePanelUI, NewTabPageUI, BookmarksSidePanelUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<whats_new::mojom::PageHandlerFactory,
                                          WhatsNewUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
   RegisterWebUIControllerInterfaceBinder<
       browser_command::mojom::CommandHandlerFactory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       WhatsNewUI,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       NewTabPageUI>(map);
@@ -525,7 +525,7 @@ void PopulateChromeWebUIFrameBindersPartsDesktop(
   RegisterWebUIControllerInterfaceBinder<
       guest_contents::mojom::GuestContentsHost, WebUIBrowserUI>(map);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 
