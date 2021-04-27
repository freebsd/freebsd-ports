--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1242,11 +1242,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif // !defined(OS_MAC) && !BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#endif // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_MAC)
   { key::kFullscreenAllowed,
@@ -1594,7 +1594,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 
 // TODO(crbug/1169547) Remove `BUILDFLAG(IS_CHROMEOS_LACROS)` once the
 // migration is complete.
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || \
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
   handlers->AddHandler(
       std::make_unique<
@@ -1602,7 +1602,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
           key::kContextAwareAccessSignalsAllowlist,
           enterprise_connectors::kContextAwareAccessSignalsAllowlistPref,
           chrome_schema));
-#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_WIN) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   std::vector<std::unique_ptr<ConfigurationPolicyHandler>>
@@ -1950,13 +1950,13 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
 
 // TODO(crbug.com/1175651): Remove BUILDFLAG(IS_CHROMEOS_LACROS)
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleSchemaValidatingPolicyHandler>(
       key::kWebAppSettings, prefs::kWebAppSettings, chrome_schema,
       SCHEMA_ALLOW_UNKNOWN,
       SimpleSchemaValidatingPolicyHandler::RECOMMENDED_PROHIBITED,
       SimpleSchemaValidatingPolicyHandler::MANDATORY_ALLOWED));
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
@@ -1969,7 +1969,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   handlers->AddHandler(std::make_unique<SimpleDeprecatingPolicyHandler>(
       std::make_unique<SimplePolicyHandler>(key::kAllowNativeNotifications,
                                             prefs::kAllowNativeNotifications,
@@ -1977,7 +1977,7 @@ std::unique_ptr<ConfigurationPolicyHandlerList> BuildH
       std::make_unique<SimplePolicyHandler>(key::kAllowSystemNotifications,
                                             prefs::kAllowSystemNotifications,
                                             base::Value::Type::BOOLEAN)));
-#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#endif  // defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 
   return handlers;
 }
