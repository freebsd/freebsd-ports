--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -14,7 +14,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/signals/signals_service_impl.h"
 #include "chrome/browser/profiles/profile.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -44,7 +44,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(
   decorators.push_back(
       std::make_unique<ContentSignalsDecorator>(policy_blocklist_service));
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   policy::ChromeBrowserPolicyConnector* browser_policy_connector =
       g_browser_process->browser_policy_connector();
   DCHECK(browser_policy_connector);
