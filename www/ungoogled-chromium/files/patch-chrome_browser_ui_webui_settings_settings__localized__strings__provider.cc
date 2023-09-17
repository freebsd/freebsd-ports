--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2023-09-17 07:59:53 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -134,7 +134,7 @@
 #include "chrome/browser/ui/webui/settings/chromeos/constants/routes.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -154,7 +154,7 @@
 #include "chrome/browser/ui/webui/certificate_manager_localized_strings_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -254,7 +254,7 @@ void AddCommonStrings(content::WebUIDataSource* html_s
       base::FeatureList::IsEnabled(
           supervised_user::kClearingCookiesKeepsSupervisedUsersSignedIn));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool allow_qt_theme = base::FeatureList::IsEnabled(ui::kAllowQt);
 #else
   bool allow_qt_theme = false;
@@ -415,7 +415,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
     {"huge", IDS_SETTINGS_HUGE_FONT_SIZE},
     {"sidePanelAlignLeft", IDS_SETTINGS_SIDE_PANEL_ALIGN_LEFT},
     {"sidePanelAlignRight", IDS_SETTINGS_SIDE_PANEL_ALIGN_RIGHT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"gtkTheme", IDS_SETTINGS_GTK_THEME},
     {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
     {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -425,7 +425,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 #else
     {"resetToDefaultTheme", IDS_SETTINGS_RESET_TO_DEFAULT_THEME},
 #endif
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
     {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -450,7 +450,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
