--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -244,7 +244,7 @@
 #include "components/spellcheck/browser/pref_names.h"
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/idle/action.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
@@ -569,7 +569,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kManagedDefaultSmartCardConnectSetting,
     base::Value::Type::INTEGER },
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDeletingUndecryptablePasswordsEnabled,
     password_manager::prefs::kDeletingUndecryptablePasswordsEnabled,
     base::Value::Type::BOOLEAN },
@@ -928,7 +928,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif // BUILDFLAG(ENABLE_EXTENSIONS_CORE)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) \
-     || BUILDFLAG(IS_MAC)
+     || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kRequireOnlineRevocationChecksForLocalAnchors,
     prefs::kCertRevocationCheckingRequiredLocalAnchors,
     base::Value::Type::BOOLEAN },
@@ -937,7 +937,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif  // #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
         // || BUILDFLAG(IS_WIN)  || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kFullscreenAllowed,
     prefs::kFullscreenAllowed,
     base::Value::Type::BOOLEAN },
@@ -1810,7 +1810,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER},
 #endif // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kGSSAPILibraryName,
     prefs::kGSSAPILibraryName,
     base::Value::Type::STRING },
@@ -1875,7 +1875,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kNetworkServiceSandboxEnabled,
     prefs::kNetworkServiceSandboxEnabled,
     base::Value::Type::BOOLEAN },
@@ -1895,12 +1895,12 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
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
@@ -1911,7 +1911,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kLiveTranslateEnabled,
     base::Value::Type::BOOLEAN },
 #endif // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDefaultBrowserSettingEnabled,
     prefs::kDefaultBrowserSettingEnabled,
     base::Value::Type::BOOLEAN },
@@ -1923,7 +1923,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) \
-    || BUILDFLAG(IS_CHROMEOS)
+    || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAutoplayAllowed,
     prefs::kAutoplayAllowed,
     base::Value::Type::BOOLEAN },
@@ -2024,7 +2024,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
     base::Value::Type::STRING },
@@ -2129,7 +2129,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -2203,7 +2203,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     ash::prefs::kUrlParameterToAutofillSAMLUsername,
     base::Value::Type::STRING },
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterExtensionAttributionEnabled,
     prefs::kNTPFooterExtensionAttributionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2238,7 +2238,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kRestrictCoreSharingOnRenderer,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kOutOfProcessSystemDnsResolutionEnabled,
     prefs::kOutOfProcessSystemDnsResolutionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2266,7 +2266,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER },
 #endif
 #if BUILDFLAG(ENABLE_EXTENSIONS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kExtensionInstallTypeBlocklist,
     extensions::pref_names::kExtensionInstallTypeBlocklist,
     base::Value::Type::LIST},
@@ -2289,7 +2289,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
   { key::kTabCompareSettings,
     optimization_guide::prefs::kProductSpecificationsEnterprisePolicyAllowed,
     base::Value::Type::INTEGER},
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   { key::kChromeForTestingAllowed,
     prefs::kChromeForTestingAllowed,
     base::Value::Type::BOOLEAN },
@@ -2365,7 +2365,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     policy_prefs::kBuiltInAIAPIsEnabled,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_FUCHSIA)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterManagementNoticeEnabled,
     prefs::kNTPFooterManagementNoticeEnabled,
     base::Value::Type::BOOLEAN },
@@ -2497,7 +2497,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   // Policies for all platforms - End
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<IntRangePolicyHandler>(
       key::kMemorySaverModeSavings,
       performance_manager::user_tuning::prefs::kMemorySaverModeAggressiveness,
@@ -2778,7 +2778,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       key::kBrowsingDataLifetime, browsing_data::prefs::kBrowsingDataLifetime,
       chrome_schema));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<GuestModePolicyHandler>());
   handlers->AddHandler(std::make_unique<LocalSyncPolicyHandler>());
   handlers->AddHandler(std::make_unique<ThemeColorPolicyHandler>());
@@ -3213,7 +3213,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif
 
 #if BUILDFLAG(ENABLE_SPELLCHECK)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SpellcheckLanguagePolicyHandler>());
   handlers->AddHandler(
       std::make_unique<SpellcheckLanguageBlocklistPolicyHandler>(
@@ -3221,7 +3221,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimplePolicyHandler>(
       key::kAllowSystemNotifications, prefs::kAllowSystemNotifications,
       base::Value::Type::BOOLEAN));
@@ -3274,7 +3274,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   std::vector<GenAiDefaultSettingsPolicyHandler::GenAiPolicyDetails>
       gen_ai_default_policies;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   gen_ai_default_policies.emplace_back(
       key::kAutofillPredictionSettings,
       optimization_guide::prefs::
