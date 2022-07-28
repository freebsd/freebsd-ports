--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2022-07-22 17:30:31 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -29,7 +29,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseDefaultTheme,
                           base::Unretained(this)));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -43,7 +43,7 @@ void AppearanceHandler::HandleUseDefaultTheme(const ba
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 void AppearanceHandler::HandleUseSystemTheme(const base::Value::List& args) {
   if (profile_->IsChild())
     NOTREACHED();
