--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2019-10-21 19:06:24 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -27,7 +27,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseDefaultTheme,
                           base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -39,7 +39,7 @@ void AppearanceHandler::HandleUseDefaultTheme(const ba
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
