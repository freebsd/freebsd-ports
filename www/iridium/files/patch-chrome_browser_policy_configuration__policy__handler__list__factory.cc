--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2026-11-17 21:17:00 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -274,7 +274,7 @@
 #include "components/spellcheck/browser/pref_names.h"
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #include "chrome/browser/enterprise/idle/action.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
@@ -662,7 +662,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kManagedDefaultSmartCardConnectSetting,
     base::Value::Type::INTEGER },
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDeletingUndecryptablePasswordsEnabled,
     password_manager::prefs::kDeletingUndecryptablePasswordsEnabled,
     base::Value::Type::BOOLEAN },
@@ -998,7 +998,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif // BUILDFLAG(ENABLE_EXTENSIONS_CORE)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) \
-     || BUILDFLAG(IS_MAC)
+     || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kRequireOnlineRevocationChecksForLocalAnchors,
     prefs::kCertRevocationCheckingRequiredLocalAnchors,
     base::Value::Type::BOOLEAN },
@@ -1007,7 +1007,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::LIST },
 #endif  // #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
         // || BUILDFLAG(IS_WIN)  || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kFullscreenAllowed,
     prefs::kFullscreenAllowed,
     base::Value::Type::BOOLEAN },
@@ -1879,7 +1879,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER},
 #endif // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kGSSAPILibraryName,
     prefs::kGSSAPILibraryName,
     base::Value::Type::STRING },
@@ -1947,7 +1947,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kNetworkServiceSandboxEnabled,
     prefs::kNetworkServiceSandboxEnabled,
     base::Value::Type::BOOLEAN },
@@ -1970,17 +1970,17 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
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
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kDefaultBrowserSettingEnabled,
     prefs::kDefaultBrowserSettingEnabled,
     base::Value::Type::BOOLEAN },
@@ -1992,7 +1992,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) \
-    || BUILDFLAG(IS_CHROMEOS)
+    || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAutomatedPasswordChangeSettings,
     optimization_guide::prefs::kAutomatedPasswordChangeEnterprisePolicyAllowed,
     base::Value::Type::INTEGER },
@@ -2090,7 +2090,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
     base::Value::Type::STRING },
@@ -2204,7 +2204,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -2293,7 +2293,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     ash::prefs::kUrlParameterToAutofillSAMLUsername,
     base::Value::Type::STRING },
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterExtensionAttributionEnabled,
     prefs::kNTPFooterExtensionAttributionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2336,7 +2336,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kAndroidEntraSSOEnabled,
     base::Value::Type::INTEGER },
 #endif
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kOutOfProcessSystemDnsResolutionEnabled,
     prefs::kOutOfProcessSystemDnsResolutionEnabled,
     base::Value::Type::BOOLEAN },
@@ -2376,7 +2376,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER },
 #endif
 #if BUILDFLAG(ENABLE_EXTENSIONS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   { key::kExtensionInstallTypeBlocklist,
     extensions::pref_names::kExtensionInstallTypeBlocklist,
     base::Value::Type::LIST},
@@ -2404,7 +2404,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     optimization_guide::prefs::kFindsEnterprisePolicyAllowed,
     base::Value::Type::INTEGER},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   { key::kChromeForTestingAllowed,
     prefs::kChromeForTestingAllowed,
     base::Value::Type::BOOLEAN },
@@ -2489,7 +2489,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     policy_prefs::kBuiltInAIAPIsEnabled,
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_ANDROID)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kNTPFooterManagementNoticeEnabled,
     prefs::kNTPFooterManagementNoticeEnabled,
     base::Value::Type::BOOLEAN },
@@ -2500,7 +2500,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
   { key::kThirdPartyAiChatSettings,
     omnibox::kThirdPartyAiChatSettings,
     base::Value::Type::INTEGER },
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   { key::kEnableProxyOverrideRulesForAllUsers,
     proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers,
     base::Value::Type::INTEGER },
@@ -2627,7 +2627,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       std::make_unique<
           LocalNetworkAccessIpAddressSpaceOverridesPolicyHandler>());
   handlers->AddHandler(std::make_unique<DefaultSensorsSettingPolicyHandler>());
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(
       std::make_unique<skills::EnterprisePublishedSkillsPolicyHandler>(
           chrome_schema));
@@ -2745,7 +2745,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   // Policies for all platforms - End
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<IntRangePolicyHandler>(
       key::kMemorySaverModeSavings,
       performance_manager::user_tuning::prefs::kMemorySaverModeAggressiveness,
@@ -3029,7 +3029,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           key::kUserContextAwareAccessSignalsAllowlist,
           enterprise_connectors::kUserContextAwareAccessSignalsAllowlistPref,
           chrome_schema));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<GuestModePolicyHandler>());
   handlers->AddHandler(std::make_unique<LocalSyncPolicyHandler>());
   handlers->AddHandler(std::make_unique<ThemeColorPolicyHandler>());
@@ -3065,14 +3065,14 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       std::make_unique<ManagedAccountRestrictionsPolicyHandler>(chrome_schema));
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<CloudUserOnlyPolicyChecker>(
       std::make_unique<URLSchemeListPolicyHandler>(
           key::kSaasUsageReportingDomainUrlsForProfiles,
           enterprise_reporting::kSaasUsageDomainUrlsForProfile)));
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<URLSchemeListPolicyHandler>(
       key::kSaasUsageReportingDomainUrlsForBrowsers,
       enterprise_reporting::kSaasUsageDomainUrlsForBrowser));
@@ -3109,7 +3109,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
     BUILDFLAG(IS_LINUX)
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<CloudUserOnlyPolicyChecker>(
       std::make_unique<SimplePolicyHandler>(
           key::kSecuritySignalsClientCertificatesSelectors,
@@ -3483,7 +3483,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif
 
 #if BUILDFLAG(ENABLE_SPELLCHECK)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SpellcheckLanguagePolicyHandler>());
   handlers->AddHandler(
       std::make_unique<SpellcheckLanguageBlocklistPolicyHandler>(
@@ -3491,7 +3491,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimplePolicyHandler>(
       key::kAllowSystemNotifications, prefs::kAllowSystemNotifications,
       base::Value::Type::BOOLEAN));
@@ -3530,7 +3530,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
   std::vector<GenAiDefaultSettingsPolicyHandler::GenAiPolicyDetails>
       gen_ai_default_policies;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   gen_ai_default_policies.emplace_back(
       key::kHelpMeWriteSettings,
       optimization_guide::prefs::kComposeEnterprisePolicyAllowed);
@@ -3672,7 +3672,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       glic::prefs::kGlicActuationOnWebBlockedForURLs));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(
       std::make_unique<GeminiEnterpriseSettingsPolicyHandler>(chrome_schema));
   handlers->AddHandler(std::make_unique<GeminiEnterpriseUrlPolicyHandler>());
