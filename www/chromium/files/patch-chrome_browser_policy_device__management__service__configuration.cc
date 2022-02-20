--- chrome/browser/policy/device_management_service_configuration.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/policy/device_management_service_configuration.cc
@@ -19,7 +19,7 @@
 #include "chromeos/system/statistics_provider.h"
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
 #include "chrome/browser/enterprise/connectors/common.h"
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
@@ -97,7 +97,7 @@ DeviceManagementServiceConfiguration::GetEncryptedRepo
 std::string
 DeviceManagementServiceConfiguration::GetReportingConnectorServerUrl(
     content::BrowserContext* context) const {
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     ((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(OS_ANDROID))
   auto* service =
       enterprise_connectors::ConnectorsServiceFactory::GetForBrowserContext(
