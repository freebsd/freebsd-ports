--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -38,7 +38,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
                           base::Unretained(this), ui::SystemTheme::kDefault));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useGtkTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
