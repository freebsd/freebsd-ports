--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2021-12-31 00:57:23 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1416,11 +1416,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !defined(OS_MAC) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_MAC)
   { key::kFullscreenAllowed,
@@ -1531,7 +1531,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::INTEGER },
 #endif
 
-#if BUILDFLAG(ENABLE_EXTENSIONS) && (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX))
+#if BUILDFLAG(ENABLE_EXTENSIONS) && (defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD))
   { key::kChromeAppsEnabled,
     extensions::pref_names::kChromeAppsEnabled,
     base::Value::Type::BOOLEAN },
@@ -1801,7 +1801,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
   handlers->AddHandler(
       std::make_unique<
@@ -1809,7 +1809,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           key::kContextAwareAccessSignalsAllowlist,
           enterprise_connectors::kContextAwareAccessSignalsAllowlistPref,
           chrome_schema));
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) ||
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 #if defined(OS_CHROMEOS)
@@ -2166,14 +2166,14 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::RECOMMENDED_PROHIBITED,
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   handlers->AddHandler(std::make_unique<SimpleSchemaValidatingPolicyHandler>(
       key::kWebAppSettings, prefs::kWebAppSettings, chrome_schema,
       SCHEMA_ALLOW_UNKNOWN,
       SimpleSchemaValidatingPolicyHandler::RECOMMENDED_PROHIBITED,
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_FUCHSIA)
 
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
@@ -2198,7 +2198,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           policy::key::kSpellcheckLanguageBlocklist));
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleDeprecatingPolicyHandler>(
       std::make_unique<SimplePolicyHandler>(key::kAllowNativeNotifications,
                                             prefs::kAllowNativeNotifications,
@@ -2206,7 +2206,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       std::make_unique<SimplePolicyHandler>(key::kAllowSystemNotifications,
                                             prefs::kAllowSystemNotifications,
                                             base::Value::Type::BOOLEAN)));
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   return handlers;
 }
