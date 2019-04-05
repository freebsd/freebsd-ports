--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -31,7 +31,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseDefaultTheme,
                           base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -59,7 +59,7 @@ void AppearanceHandler::HandleUseDefaultTheme(const ba
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
