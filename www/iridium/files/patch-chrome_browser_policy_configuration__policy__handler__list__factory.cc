--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2020-03-16 18:40:29 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -118,7 +118,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
 
@@ -355,11 +355,11 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
   { key::kWebComponentsV0Enabled,
     prefs::kWebComponentsV0Enabled,
     base::Value::Type::BOOLEAN },
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   { key::kAuthNegotiateDelegateByKdcPolicy,
     prefs::kAuthNegotiateDelegateByKdcPolicy,
     base::Value::Type::BOOLEAN },
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_POSIX)
   { key::kNtlmV2Enabled,
     prefs::kNtlmV2Enabled,
@@ -1163,7 +1163,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kExternalProtocolDialogShowAlwaysOpenCheckbox,
     base::Value::Type::BOOLEAN },
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
     base::Value::Type::STRING },
@@ -1203,7 +1203,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     browser_switcher::prefs::kChromeParameters,
     base::Value::Type::LIST },
 #endif
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
   { key::kBrowserGuestModeEnforced,
     prefs::kBrowserGuestModeEnforced,
     base::Value::Type::BOOLEAN },
