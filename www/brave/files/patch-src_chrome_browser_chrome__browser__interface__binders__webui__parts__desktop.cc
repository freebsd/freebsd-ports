--- src/chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/chrome_browser_interface_binders_webui_parts_desktop.cc
@@ -141,7 +141,7 @@
 #include "ui/webui/resources/cr_components/theme_color_picker/theme_color_picker.mojom.h"
 #include "ui/webui/resources/js/browser_command/browser_command.mojom.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_home/app_home.mojom.h"
 #include "chrome/browser/ui/webui/app_home/app_home_ui.h"
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
@@ -360,7 +360,7 @@ void PopulateChromeWebUIFrameBindersPart
         HistoryClustersSidePanelUI, NewTabPageUI, BookmarksSidePanelUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<whats_new::mojom::PageHandlerFactory,
                                          WhatsNewUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -390,7 +390,7 @@ void PopulateChromeWebUIFrameBindersPart
 
   RegisterWebUIControllerInterfaceBinder<
       browser_command::mojom::CommandHandlerFactory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       WhatsNewUI,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
       NewTabPageUI>(map);
@@ -583,7 +583,7 @@ void PopulateChromeWebUIFrameBindersPart
         DrivePickerUntrustedHostUI>(map);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       app_management::mojom::PageHandlerFactory, WebAppSettingsUI>(map);
 
@@ -609,7 +609,7 @@ void PopulateChromeWebUIFrameBindersPart
                                          webapps::AppHomeUI>(map);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWebUIControllerInterfaceBinder<updater_ui::mojom::PageHandlerFactory,
                                          UpdaterUI>(map);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
