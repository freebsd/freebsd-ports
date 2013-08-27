--- chrome/browser/ui/webui/options/browser_options_handler.cc.orig	2013-08-23 16:36:11.000000000 +0300
+++ chrome/browser/ui/webui/options/browser_options_handler.cc	2013-08-23 16:38:28.000000000 +0300
@@ -337,7 +337,7 @@
     { "toolbarShowHomeButton", IDS_OPTIONS_TOOLBAR_SHOW_HOME_BUTTON },
     { "translateEnableTranslate",
       IDS_OPTIONS_TRANSLATE_ENABLE_TRANSLATE },
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     { "showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS },
     { "themesNativeButton", IDS_THEMES_GTK_BUTTON },
     { "themesSetClassic", IDS_THEMES_SET_CLASSIC },
@@ -583,7 +583,7 @@
       "themesReset",
       base::Bind(&BrowserOptionsHandler::ThemesReset,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   web_ui()->RegisterMessageCallback(
       "themesSetNative",
       base::Bind(&BrowserOptionsHandler::ThemesSetNative,
@@ -1327,7 +1327,7 @@
   ThemeService* theme_service = ThemeServiceFactory::GetForProfile(profile);
   bool is_native_theme = false;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   is_native_theme = theme_service->UsingNativeTheme();
   base::FundamentalValue native_theme_enabled(!is_native_theme &&
                                               !profile_is_managed);
@@ -1350,7 +1350,7 @@
   ThemeServiceFactory::GetForProfile(profile)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void BrowserOptionsHandler::ThemesSetNative(const ListValue* args) {
   content::RecordAction(UserMetricsAction("Options_GtkThemeSet"));
   Profile* profile = Profile::FromWebUI(web_ui());
