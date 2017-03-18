--- chrome/browser/ui/webui/settings/md_settings_localized_strings_provider.cc.orig	2017-03-09 20:04:29 UTC
+++ chrome/browser/ui/webui/settings/md_settings_localized_strings_provider.cc
@@ -287,7 +287,7 @@ void AddAppearanceStrings(content::WebUI
     {"appearancePageTitle", IDS_SETTINGS_APPEARANCE},
     {"exampleDotCom", IDS_SETTINGS_EXAMPLE_DOT_COM},
     {"themes", IDS_SETTINGS_THEMES},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     {"systemTheme", IDS_SETTINGS_SYSTEM_THEME},
     {"useSystemTheme", IDS_SETTINGS_USE_SYSTEM_THEME},
     {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
@@ -307,7 +307,7 @@ void AddAppearanceStrings(content::WebUI
     {"openWallpaperApp", IDS_SETTINGS_OPEN_WALLPAPER_APP},
     {"setWallpaper", IDS_SETTINGS_SET_WALLPAPER},
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
   };
