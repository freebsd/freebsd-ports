--- chrome/browser/ui/browser_view_prefs.cc.orig	2021-09-24 04:26:00 UTC
+++ chrome/browser/ui/browser_view_prefs.cc
@@ -29,7 +29,7 @@ const char kTabStripLayoutType[] = "tab_strip_layout_t
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 bool GetCustomFramePrefDefault() {
 #if defined(USE_OZONE)
   if (features::IsUsingOzonePlatform()) {
@@ -57,10 +57,10 @@ void RegisterBrowserViewProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kUseCustomChromeFrame,
                                 GetCustomFramePrefDefault());
-#endif  // (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) &&
+#endif  // (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) &&
         // defined(!OS_CHROMEOS)
 }
 
