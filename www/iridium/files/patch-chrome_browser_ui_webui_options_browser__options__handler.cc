--- chrome/browser/ui/webui/options/browser_options_handler.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.cc
@@ -608,13 +608,13 @@ void BrowserOptionsHandler::GetLocalized
     { "syncButtonTextStart", IDS_SYNC_SETUP_BUTTON_LABEL },
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
     { "showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS },
     { "themesNativeButton", IDS_THEMES_GTK_BUTTON },
     { "themesSetClassic", IDS_THEMES_SET_CLASSIC },
 #else
     { "themes", IDS_THEMES_GROUP_NAME },
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // defined(OS_POSIX) && !defined(OS_CHROMEOS)
 
 #if defined(OS_CHROMEOS) && defined(USE_ASH)
     { "setWallpaper", IDS_SET_WALLPAPER_BUTTON },
@@ -859,7 +859,7 @@ void BrowserOptionsHandler::RegisterMess
       "requestProfilesInfo",
       base::Bind(&BrowserOptionsHandler::HandleRequestProfilesInfo,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "themesSetNative",
       base::Bind(&BrowserOptionsHandler::ThemesSetNative,
@@ -1519,7 +1519,7 @@ void BrowserOptionsHandler::ObserveTheme
   ThemeService* theme_service = ThemeServiceFactory::GetForProfile(profile);
   bool is_system_theme = false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   bool profile_is_supervised = profile->IsSupervised();
   is_system_theme = theme_service->UsingSystemTheme();
   base::Value native_theme_enabled(!is_system_theme && !profile_is_supervised);
@@ -1540,7 +1540,7 @@ void BrowserOptionsHandler::ThemesReset(
   ThemeServiceFactory::GetForProfile(profile)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
 void BrowserOptionsHandler::ThemesSetNative(const base::ListValue* args) {
   content::RecordAction(UserMetricsAction("Options_GtkThemeSet"));
   Profile* profile = Profile::FromWebUI(web_ui());
