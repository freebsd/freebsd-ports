--- chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_connector_service_factory.cc
@@ -12,7 +12,7 @@
 #include "components/keyed_service/content/browser_context_dependency_manager.h"
 #include "components/keyed_service/core/keyed_service.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/enterprise/connectors/device_trust/browser/browser_device_trust_connector_service.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -37,7 +37,7 @@ DeviceTrustConnectorService* DeviceTrustConnectorServi
 
 bool DeviceTrustConnectorServiceFactory::ServiceIsCreatedWithBrowserContext()
     const {
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   return IsDeviceTrustConnectorFeatureEnabled();
 #else
   return false;
@@ -58,7 +58,7 @@ KeyedService* DeviceTrustConnectorServiceFactory::Buil
 
   DeviceTrustConnectorService* service = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   if (IsDeviceTrustConnectorFeatureEnabled()) {
     auto* key_manager = g_browser_process->browser_policy_connector()
                             ->chrome_browser_cloud_management_controller()
