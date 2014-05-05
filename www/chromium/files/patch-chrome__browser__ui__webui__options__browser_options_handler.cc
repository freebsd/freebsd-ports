--- ./chrome/browser/ui/webui/options/browser_options_handler.cc.orig	2014-04-24 22:35:00.000000000 +0200
+++ ./chrome/browser/ui/webui/options/browser_options_handler.cc	2014-04-24 23:23:43.000000000 +0200
@@ -313,7 +313,8 @@
     { "toolbarShowHomeButton", IDS_OPTIONS_TOOLBAR_SHOW_HOME_BUTTON },
     { "translateEnableTranslate",
       IDS_OPTIONS_TRANSLATE_ENABLE_TRANSLATE },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
     { "showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS },
     { "themesNativeButton", IDS_THEMES_GTK_BUTTON },
     { "themesSetClassic", IDS_THEMES_SET_CLASSIC },
@@ -620,7 +621,8 @@
       "requestProfilesInfo",
       base::Bind(&BrowserOptionsHandler::HandleRequestProfilesInfo,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   web_ui()->RegisterMessageCallback(
       "themesSetNative",
       base::Bind(&BrowserOptionsHandler::ThemesSetNative,
@@ -1204,7 +1206,8 @@
   ThemeService* theme_service = ThemeServiceFactory::GetForProfile(profile);
   bool is_native_theme = false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   bool profile_is_managed = profile->IsManaged();
   is_native_theme = theme_service->UsingNativeTheme();
   base::FundamentalValue native_theme_enabled(!is_native_theme &&
@@ -1226,7 +1229,8 @@
   ThemeServiceFactory::GetForProfile(profile)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
 void BrowserOptionsHandler::ThemesSetNative(const base::ListValue* args) {
   content::RecordAction(UserMetricsAction("Options_GtkThemeSet"));
   Profile* profile = Profile::FromWebUI(web_ui());
