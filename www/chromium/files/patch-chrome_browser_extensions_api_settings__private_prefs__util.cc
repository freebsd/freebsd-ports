--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -169,7 +169,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   (*s_allowlist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -179,7 +179,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   // Appearance settings.
   (*s_allowlist)[::prefs::kCurrentThemeID] =
       settings_api::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   (*s_allowlist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
