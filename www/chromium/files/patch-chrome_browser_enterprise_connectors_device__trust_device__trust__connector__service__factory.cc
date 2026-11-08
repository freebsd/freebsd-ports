--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -10,7 +10,7 @@
 #include "components/enterprise/device_trust/core/device_trust_connector_service.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/browser/signing_key_policy_observer.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -40,7 +40,7 @@ DeviceTrustConnectorService* DeviceTrustConnectorServi
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
@@ -89,7 +89,7 @@ DeviceTrustConnectorServiceFactory::BuildServiceInstan
   std::unique_ptr<DeviceTrustConnectorService> service =
       std::make_unique<DeviceTrustConnectorService>(profile->GetPrefs());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // `system_network_context_manager` can be null in unit test environments
   // (e.g. `TestingBrowserProcess`) where the network service and Chrome Browser
   // Cloud Management (CBCM) are not initialized. In that case, avoid
