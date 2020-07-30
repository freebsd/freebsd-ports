--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2020-07-07 21:58:13 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -1193,11 +1193,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
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
@@ -1265,11 +1265,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     base::Value::Type::BOOLEAN },
 #endif  // BUILDFLAG(ENABLE_SPELLCHECK)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   { key::kAllowNativeNotifications,
     prefs::kAllowNativeNotifications,
     base::Value::Type::BOOLEAN },
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   { key::kRequiredClientCertificateForUser,
