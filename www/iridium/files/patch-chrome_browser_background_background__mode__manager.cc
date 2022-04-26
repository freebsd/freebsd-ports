--- chrome/browser/background/background_mode_manager.cc.orig	2022-04-03 12:23:22 UTC
+++ chrome/browser/background/background_mode_manager.cc
@@ -376,7 +376,7 @@ void BackgroundModeManager::RegisterPrefs(PrefRegistry
   registry->RegisterBooleanPref(prefs::kChromeCreatedLoginItem, false);
   registry->RegisterBooleanPref(prefs::kMigratedLoginItemPref, false);
 #endif
-  registry->RegisterBooleanPref(prefs::kBackgroundModeEnabled, false);
+  registry->RegisterBooleanPref(prefs::kBackgroundModeEnabled, true);
 }
 
 void BackgroundModeManager::RegisterProfile(Profile* profile) {
@@ -899,7 +899,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
     return gfx::ImageSkia();
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
