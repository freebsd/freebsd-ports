--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2017-02-02 02:02:49 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -83,7 +83,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -93,7 +93,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_private::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_private::PrefType::PREF_TYPE_BOOLEAN;
 #endif
