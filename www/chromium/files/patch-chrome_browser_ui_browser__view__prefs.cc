--- chrome/browser/ui/browser_view_prefs.cc.orig	2018-12-30 03:14:18.095305000 +0100
+++ chrome/browser/ui/browser_view_prefs.cc	2018-12-30 03:14:37.732345000 +0100
@@ -34,7 +34,7 @@
 
 void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   bool custom_frame_pref_default = false;
 #if defined(USE_X11)
   custom_frame_pref_default = ui::GetCustomFramePrefDefault();
@@ -45,7 +45,7 @@
 #endif
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 custom_frame_pref_default);
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX && !OS_CHROMEOS) || defined(OS_BSD)
 }
 
 void MigrateBrowserTabStripPrefs(PrefService* prefs) {
