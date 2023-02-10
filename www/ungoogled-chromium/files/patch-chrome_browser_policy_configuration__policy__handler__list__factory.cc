--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2023-01-13 08:56:02 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -191,12 +191,12 @@
 #include "components/spellcheck/browser/pref_names.h"
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/pref_names.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/policy/web_app_settings_policy_handler.h"
 #endif
 
@@ -701,14 +701,14 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kManagedDefaultGeolocationSetting,
     base::Value::Type::INTEGER },
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) \
-    || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_MAC)
+    || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kRequireOnlineRevocationChecksForLocalAnchors,
     prefs::kCertRevocationCheckingRequiredLocalAnchors,
     base::Value::Type::BOOLEAN },
 #endif  // #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
         // || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_MAC)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) \
-    || BUILDFLAG(IS_FUCHSIA)
+    || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   { key::kFullscreenAllowed,
     prefs::kFullscreenAllowed,
     base::Value::Type::BOOLEAN },
@@ -1332,7 +1332,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kGSSAPILibraryName,
     prefs::kGSSAPILibraryName,
     base::Value::Type::STRING },
@@ -1402,18 +1402,18 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kTotalMemoryLimitMb,
     base::Value::Type::INTEGER },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kBackgroundModeEnabled,
     prefs::kBackgroundModeEnabled,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kUnmanagedDeviceSignalsConsentFlowEnabled,
     device_signals::prefs::kUnmanagedDeviceSignalsConsentFlowEnabled,
     base::Value::Type::BOOLEAN },
 #endif // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) \
-    || BUILDFLAG(IS_FUCHSIA)
+    || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   { key::kDefaultBrowserSettingEnabled,
     prefs::kDefaultBrowserSettingEnabled,
     base::Value::Type::BOOLEAN },
@@ -1426,7 +1426,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
         // || BUILDFLAG(IS_FUCHSIA)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) \
-    || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   { key::kAutoplayAllowed,
     prefs::kAutoplayAllowed,
     base::Value::Type::BOOLEAN },
@@ -1533,7 +1533,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
     base::Value::Type::STRING },
@@ -1620,7 +1620,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -1667,7 +1667,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(ENABLE_EXTENSIONS) && (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) \
-    || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+    || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   { key::kChromeAppsEnabled,
     extensions::pref_names::kChromeAppsEnabled,
     base::Value::Type::BOOLEAN },
@@ -1727,7 +1727,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
   { key::kPrefixedStorageInfoEnabled,
     storage::kPrefixedStorageInfoEnabled,
     base::Value::Type::BOOLEAN },
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS_ASH)
   { key::kHighEfficiencyModeEnabled,
     performance_manager::user_tuning::prefs::kHighEfficiencyModeEnabled,
     base::Value::Type::BOOLEAN },
@@ -2018,7 +2018,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       key::kBrowsingDataLifetime, browsing_data::prefs::kBrowsingDataLifetime,
       chrome_schema));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<LocalSyncPolicyHandler>());
   handlers->AddHandler(std::make_unique<ThemeColorPolicyHandler>());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -2373,7 +2373,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           chrome_schema));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(
       std::make_unique<web_app::WebAppSettingsPolicyHandler>(chrome_schema));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
@@ -2386,7 +2386,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif
 
 #if BUILDFLAG(ENABLE_SPELLCHECK)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SpellcheckLanguagePolicyHandler>());
   handlers->AddHandler(
       std::make_unique<SpellcheckLanguageBlocklistPolicyHandler>(
@@ -2394,7 +2394,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimplePolicyHandler>(
       key::kAllowSystemNotifications, prefs::kAllowSystemNotifications,
       base::Value::Type::BOOLEAN));
