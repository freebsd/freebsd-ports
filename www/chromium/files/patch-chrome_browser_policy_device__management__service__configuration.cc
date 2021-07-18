--- chrome/browser/policy/device_management_service_configuration.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -20,7 +20,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif
@@ -98,7 +98,7 @@ std::string
 DeviceManagementServiceConfiguration::GetReportingConnectorServerUrl(
     content::BrowserContext* context) {
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID)) || defined(OS_BSD)
   auto* service =
       enterprise_connectors::ConnectorsServiceFactory::GetForBrowserContext(
           context);
