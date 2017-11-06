--- chrome/browser/ui/webui/options/browser_options_handler.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/ui/webui/options/browser_options_handler.cc
@@ -592,13 +592,13 @@ void BrowserOptionsHandler::GetLocalizedValues(base::D
     {"syncButtonTextStart", IDS_SYNC_SETUP_BUTTON_LABEL},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
     {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
     {"themesNativeButton", IDS_THEMES_GTK_BUTTON},
     {"themesSetClassic", IDS_THEMES_SET_CLASSIC},
 #else
     {"themes", IDS_THEMES_GROUP_NAME},
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // defined(OS_POSIX) && !defined(OS_CHROMEOS)
 
 #if defined(OS_CHROMEOS)
     {"setWallpaper", IDS_SET_WALLPAPER_BUTTON},
@@ -845,7 +845,7 @@ void BrowserOptionsHandler::RegisterMessages() {
       "requestProfilesInfo",
       base::Bind(&BrowserOptionsHandler::HandleRequestProfilesInfo,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "themesSetNative",
       base::Bind(&BrowserOptionsHandler::ThemesSetNative,
@@ -1505,7 +1505,7 @@ void BrowserOptionsHandler::ObserveThemeChanged() {
   ThemeService* theme_service = ThemeServiceFactory::GetForProfile(profile);
   bool is_system_theme = false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   bool profile_is_supervised = profile->IsSupervised();
   is_system_theme = theme_service->UsingSystemTheme();
   base::Value native_theme_enabled(!is_system_theme && !profile_is_supervised);
@@ -1526,7 +1526,7 @@ void BrowserOptionsHandler::ThemesReset(const base::Li
   ThemeServiceFactory::GetForProfile(profile)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
 void BrowserOptionsHandler::ThemesSetNative(const base::ListValue* args) {
   base::RecordAction(UserMetricsAction("Options_GtkThemeSet"));
   Profile* profile = Profile::FromWebUI(web_ui());
