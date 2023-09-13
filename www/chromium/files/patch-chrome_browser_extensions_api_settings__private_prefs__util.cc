--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2023-09-13 12:11:42 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -198,7 +198,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   (*s_allowlist)[::prefs::kSidePanelHorizontalAlignment] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -210,7 +210,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
       settings_api::PrefType::PREF_TYPE_STRING;
   (*s_allowlist)[::prefs::kPolicyThemeColor] =
       settings_api::PrefType::PREF_TYPE_NUMBER;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUsesSystemThemeDeprecated] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
   (*s_allowlist)[::prefs::kSystemTheme] =
