--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -408,7 +408,7 @@ CustomThemeSupplier* AppBrowserController::GetThemeSup
 }
 
 bool AppBrowserController::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
