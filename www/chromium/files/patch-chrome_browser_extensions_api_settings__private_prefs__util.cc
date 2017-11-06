--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2017-06-05 19:03:02 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -84,7 +84,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -94,7 +94,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetWhitelist
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_private::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
 #endif
