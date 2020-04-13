--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2020-03-16 18:40:30 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -333,7 +333,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
     {"enterCustomWebAddress", IDS_SETTINGS_ENTER_CUSTOM_WEB_ADDRESS},
     {"homeButtonDisabled", IDS_SETTINGS_HOME_BUTTON_DISABLED},
     {"themes", IDS_SETTINGS_THEMES},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"systemTheme", IDS_SETTINGS_SYSTEM_THEME},
     {"useSystemTheme", IDS_SETTINGS_USE_SYSTEM_THEME},
     {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
@@ -348,7 +348,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
     {"changeHomePage", IDS_SETTINGS_CHANGE_HOME_PAGE},
     {"themesGalleryUrl", IDS_THEMES_GALLERY_URL},
     {"chooseFromWebStore", IDS_SETTINGS_WEB_STORE},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if defined(OS_MACOSX)
