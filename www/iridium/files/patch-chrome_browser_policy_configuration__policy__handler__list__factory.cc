--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc
@@ -107,7 +107,7 @@
 #include "chrome/browser/policy/browser_signin_policy_handler.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -939,7 +939,7 @@ const PolicyToPreferenceMapEntry kSimplePolicyMap[] = 
     prefs::kEnterpriseHardwarePlatformAPIEnabled,
     base::Value::Type::BOOLEAN },
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
