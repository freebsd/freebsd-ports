--- chrome/browser/policy/configuration_policy_handler_list_factory.cc.orig	2019-02-06 22:23:27.096383000 +0100
+++ chrome/browser/policy/configuration_policy_handler_list_factory.cc	2019-02-07 00:04:06.202061000 +0100
@@ -104,7 +104,7 @@
 #include "chrome/browser/policy/browser_signin_policy_handler.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -928,7 +928,7 @@
     prefs::kEnterpriseHardwarePlatformAPIEnabled,
     base::Value::Type::BOOLEAN },
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   { key::kAlternativeBrowserPath,
     browser_switcher::prefs::kAlternativeBrowserPath,
