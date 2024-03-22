--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -205,7 +205,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   (*s_allowlist)[::prefs::kSidePanelHorizontalAlignment] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -214,7 +214,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
   // Appearance settings.
   (*s_allowlist)[::prefs::kCurrentThemeID] = settings_api::PrefType::kString;
   (*s_allowlist)[::prefs::kPolicyThemeColor] = settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
