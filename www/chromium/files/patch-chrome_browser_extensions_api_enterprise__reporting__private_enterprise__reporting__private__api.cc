--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc
@@ -155,7 +155,7 @@ EnterpriseReportingPrivateGetDeviceIdFunction::
 
 // getPersistentSecret
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 EnterpriseReportingPrivateGetPersistentSecretFunction::
     EnterpriseReportingPrivateGetPersistentSecretFunction() = default;
@@ -207,7 +207,7 @@ void EnterpriseReportingPrivateGetPersistentSecretFunc
   }
 }
 
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
 // getDeviceData
 
