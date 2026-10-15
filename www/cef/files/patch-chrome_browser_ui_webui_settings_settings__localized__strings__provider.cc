--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -153,7 +153,7 @@
 #include "chrome/browser/ui/webui/settings/system_handler.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -163,7 +163,7 @@
 #include "device/fido/win/webauthn_api.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -288,7 +288,7 @@ void AddA11yStrings(content::WebUIDataSource* html_sou
       {"toastAlertLevelDescription",
        IDS_SETTINGS_ACCESSIBILITY_TOAST_FREQUENCY_DESCRIPTION},
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {"overscrollHistoryNavigationTitle",
        IDS_SETTINGS_OVERSCROLL_HISTORY_NAVIGATION_TITLE},
       {"overscrollHistoryNavigationSubtitle",
@@ -637,7 +637,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"uiFeatureAlignSide", IDS_SETTINGS_UI_FEATURE_ALIGN_SIDE},
       {"uiFeatureAlignTop", IDS_SETTINGS_UI_FEATURE_ALIGN_TOP},
       {"resetToDefault", IDS_SETTINGS_RESET_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"gtkTheme", IDS_SETTINGS_GTK_THEME},
       {"useGtkTheme", IDS_SETTINGS_USE_GTK_THEME},
       {"qtTheme", IDS_SETTINGS_QT_THEME},
@@ -645,11 +645,11 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
       {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
       {"useClassicTheme", IDS_SETTINGS_USE_CLASSIC_THEME},
 #endif
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
       {"resetToDefaultTheme", IDS_SETTINGS_RESET_TO_DEFAULT_THEME},
 #endif
       {"resetToolbarToDefault", IDS_SETTINGS_RESET_TOOLBAR_TO_DEFAULT},
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -692,7 +692,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
   html_source->AddString("configurableSidePanelAlignments",
                          configurable_alignments_json);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool show_custom_chrome_frame = ui::OzonePlatform::GetInstance()
                                       ->GetPlatformRuntimeProperties()
                                       .supports_server_side_window_decorations;
@@ -2099,7 +2099,7 @@ void AddSignOutDialogStrings(content::WebUIDataSource*
           g_browser_process->GetApplicationLocale())
           .spec();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   html_source->AddString(
       "syncDisconnectManagedProfileExplanation",
       l10n_util::GetStringFUTF8(
