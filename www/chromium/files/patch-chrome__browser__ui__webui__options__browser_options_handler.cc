--- ./chrome/browser/ui/webui/options/browser_options_handler.cc.orig	2014-08-12 21:01:37.000000000 +0200
+++ ./chrome/browser/ui/webui/options/browser_options_handler.cc	2014-08-13 09:56:57.000000000 +0200
@@ -333,7 +333,8 @@
     { "toolbarShowHomeButton", IDS_OPTIONS_TOOLBAR_SHOW_HOME_BUTTON },
     { "translateEnableTranslate",
       IDS_OPTIONS_TRANSLATE_ENABLE_TRANSLATE },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
     { "showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS },
     { "themesNativeButton", IDS_THEMES_GTK_BUTTON },
     { "themesSetClassic", IDS_THEMES_SET_CLASSIC },
@@ -640,7 +641,8 @@
       "requestProfilesInfo",
       base::Bind(&BrowserOptionsHandler::HandleRequestProfilesInfo,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   web_ui()->RegisterMessageCallback(
       "themesSetNative",
       base::Bind(&BrowserOptionsHandler::ThemesSetNative,
@@ -1269,7 +1271,8 @@
   ThemeService* theme_service = ThemeServiceFactory::GetForProfile(profile);
   bool is_native_theme = false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   bool profile_is_managed = profile->IsManaged();
   is_native_theme = theme_service->UsingNativeTheme();
   base::FundamentalValue native_theme_enabled(!is_native_theme &&
@@ -1291,7 +1294,8 @@
   ThemeServiceFactory::GetForProfile(profile)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
 void BrowserOptionsHandler::ThemesSetNative(const base::ListValue* args) {
   content::RecordAction(UserMetricsAction("Options_GtkThemeSet"));
   Profile* profile = Profile::FromWebUI(web_ui());
