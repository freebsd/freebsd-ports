--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1443,7 +1443,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -1552,7 +1552,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(ENABLE_EXTENSIONS) && (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(ENABLE_EXTENSIONS) && (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   { key::kChromeAppsEnabled,
     extensions::pref_names::kChromeAppsEnabled,
     base::Value::Type::BOOLEAN },
@@ -1848,7 +1848,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(
       std::make_unique<
           enterprise_connectors::EnterpriseConnectorsPolicyHandler>(
@@ -2213,7 +2213,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimpleSchemaValidatingPolicyHandler>(
       key::kWebAppSettings, prefs::kWebAppSettings, chrome_schema,
       SCHEMA_ALLOW_UNKNOWN,
@@ -2244,7 +2244,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           policy::key::kSpellcheckLanguageBlocklist));
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   handlers->AddHandler(std::make_unique<SimpleDeprecatingPolicyHandler>(
       std::make_unique<SimplePolicyHandler>(key::kAllowNativeNotifications,
                                             prefs::kAllowNativeNotifications,
