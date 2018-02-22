--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2017-12-24 02:59:37.041407000 +0100
+++ chrome/browser/ui/webui/settings/appearance_handler.cc	2017-12-24 03:00:20.310448000 +0100
@@ -33,7 +33,7 @@
       "useDefaultTheme",
       base::Bind(&AppearanceHandler::HandleUseDefaultTheme,
                  base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) 
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::Bind(&AppearanceHandler::HandleUseSystemTheme,
@@ -61,7 +61,7 @@
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
