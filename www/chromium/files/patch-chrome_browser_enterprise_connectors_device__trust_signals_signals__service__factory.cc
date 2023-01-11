--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2023-01-11 09:17:16 UTC
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -22,7 +22,7 @@
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/win/win_signals_decorator.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -62,7 +62,7 @@ std::unique_ptr<SignalsService> CreateSignalsService(P
   decorators.push_back(std::make_unique<WinSignalsDecorator>());
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   policy::CloudPolicyStore* store = nullptr;
 
   // Managed device.
