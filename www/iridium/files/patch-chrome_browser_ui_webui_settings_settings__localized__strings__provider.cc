--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2024-08-27 06:28:16 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -141,7 +141,7 @@
 #include "chrome/browser/ui/chrome_pages.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "ui/display/screen.h"
 #endif
 
@@ -160,7 +160,7 @@
 #include "chrome/browser/ui/webui/certificate_manager_localized_strings_provider.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -280,7 +280,7 @@ void AddA11yStrings(content::WebUIDataSource* html_sou
       {"focusHighlightLabel",
        IDS_SETTINGS_ACCESSIBILITY_FOCUS_HIGHLIGHT_DESCRIPTION},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {"overscrollHistoryNavigationTitle",
        IDS_SETTINGS_OVERSCROLL_HISTORY_NAVIGATION_TITLE},
       {"overscrollHistoryNavigationSubtitle",
@@ -405,7 +405,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"uiFeatureAlignLeft", IDS_SETTINGS_UI_FEATURE_ALIGN_LEFT},
       {"uiFeatureAlignRight", IDS_SETTINGS_UI_FEATURE_ALIGN_RIGHT},
       {"resetToDefault", IDS_SETTINGS_RESET_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"gtkTheme", IDS_SETTINGS_GTK_THEME},
       {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
       {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -413,7 +413,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
       {"useClassicTheme", IDS_SETTINGS_USE_CLASSIC_THEME},
 #endif
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
       {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -441,7 +441,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
