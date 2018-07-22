--- chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2018-06-13 00:10:09.000000000 +0200
+++ chrome/browser/ui/webui/settings/appearance_handler.cc	2018-07-18 23:00:36.362422000 +0200
@@ -31,7 +31,7 @@
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseDefaultTheme,
                           base::Unretained(this)));
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
   web_ui()->RegisterMessageCallback(
       "useSystemTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseSystemTheme,
@@ -59,7 +59,7 @@
   ThemeServiceFactory::GetForProfile(profile_)->UseDefaultTheme();
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_BSD) && !defined(OS_CHROMEOS)
 void AppearanceHandler::HandleUseSystemTheme(const base::ListValue* args) {
   if (profile_->IsSupervised())
     NOTREACHED();
