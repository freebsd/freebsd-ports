--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2020-09-08 19:14:00 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1232,11 +1232,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // !defined(OS_MACOSX) && !defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_MACOSX)
   { key::kFullscreenAllowed,
@@ -1304,11 +1304,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   { key::kAllowNativeNotifications,
     prefs::kAllowNativeNotifications,
     base::Value::Type::BOOLEAN },
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
   { key::kScrollToTextFragmentEnabled,
     prefs::kScrollToTextFragmentEnabled,
