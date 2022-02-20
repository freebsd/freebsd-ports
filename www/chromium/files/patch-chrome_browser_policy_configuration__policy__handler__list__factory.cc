--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1432,7 +1432,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !defined(OS_MAC) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
@@ -1541,7 +1541,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(ENABLE_EXTENSIONS) && (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX))
+#if BUILDFLAG(ENABLE_EXTENSIONS) && (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD))
   { key::kChromeAppsEnabled,
     extensions::pref_names::kChromeAppsEnabled,
     base::Value::Type::BOOLEAN },
@@ -1828,7 +1828,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 #endif  // defined(OS_ANDROID)
 
 #if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
-    defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+    defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   handlers->AddHandler(
       std::make_unique<
           enterprise_connectors::EnterpriseConnectorsPolicyHandler>(
@@ -2193,7 +2193,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleSchemaValidatingPolicyHandler>(
       key::kWebAppSettings, prefs::kWebAppSettings, chrome_schema,
       SCHEMA_ALLOW_UNKNOWN,
@@ -2224,7 +2224,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           policy::key::kSpellcheckLanguageBlocklist));
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleDeprecatingPolicyHandler>(
       std::make_unique<SimplePolicyHandler>(key::kAllowNativeNotifications,
                                             prefs::kAllowNativeNotifications,
