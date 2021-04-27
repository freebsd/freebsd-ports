--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2021-04-14 18:40:53 UTC
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -176,7 +176,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -188,7 +188,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil::GetAllowlist
       settings_api::PrefType::PREF_TYPE_STRING;
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   (*s_allowlist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
