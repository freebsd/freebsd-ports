--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -137,7 +137,7 @@
 #include "chrome/browser/ui/webui/settings/system_handler.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -146,7 +146,7 @@
 #include "device/fido/win/webauthn_api.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -271,7 +271,7 @@ void AddA11yStrings(content::WebUIDataSource* html_sou
       {"toastAlertLevelDescription",
        IDS_SETTINGS_ACCESSIBILITY_TOAST_FREQUENCY_DESCRIPTION},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {"overscrollHistoryNavigationTitle",
        IDS_SETTINGS_OVERSCROLL_HISTORY_NAVIGATION_TITLE},
       {"overscrollHistoryNavigationSubtitle",
@@ -543,7 +543,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"uiFeatureAlignLeft", IDS_SETTINGS_UI_FEATURE_ALIGN_LEFT},
       {"uiFeatureAlignRight", IDS_SETTINGS_UI_FEATURE_ALIGN_RIGHT},
       {"resetToDefault", IDS_SETTINGS_RESET_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"gtkTheme", IDS_SETTINGS_GTK_THEME},
       {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
       {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -551,11 +551,11 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
       {"useClassicTheme", IDS_SETTINGS_USE_CLASSIC_THEME},
 #endif
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"resetToDefaultTheme", IDS_SETTINGS_RESET_TO_DEFAULT_THEME},
 #endif
       {"resetToolbarToDefault", IDS_SETTINGS_RESET_TOOLBAR_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -579,7 +579,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
   html_source->AddBoolean("tabSearchIsRightAlignedAtStartup",
                           tabs::GetTabSearchTrailingTabstrip(profile));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
@@ -1577,7 +1577,7 @@ void AddSignOutDialogStrings(content::WebUIDataSource*
           g_browser_process->GetApplicationLocale())
           .spec();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   html_source->AddString(
       "syncDisconnectManagedProfileExplanation",
       l10n_util::GetStringFUTF8(
