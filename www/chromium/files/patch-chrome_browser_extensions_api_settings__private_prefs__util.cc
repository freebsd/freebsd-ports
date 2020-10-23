--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2020-09-08 19:13:59 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -163,7 +163,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -173,7 +173,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_api::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
