--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2019-04-30 22:22:33 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -128,7 +128,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -138,7 +138,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_api::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
