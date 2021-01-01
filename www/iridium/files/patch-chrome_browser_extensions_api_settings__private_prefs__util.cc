--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2020-03-16 18:40:29 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -160,7 +160,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -170,7 +170,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_api::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
