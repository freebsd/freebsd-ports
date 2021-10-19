--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc.orig	2021-09-24 18:21:22 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc
@@ -154,7 +154,7 @@ EnterpriseReportingPrivateGetDeviceIdFunction::
 
 // getPersistentSecret
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 EnterpriseReportingPrivateGetPersistentSecretFunction::
     EnterpriseReportingPrivateGetPersistentSecretFunction() = default;
@@ -206,7 +206,7 @@ void EnterpriseReportingPrivateGetPersistentSecretFunc
   }
 }
 
-#endif  // !defined(OS_LINUX)
+#endif  // !defined(OS_LINUX) && !defined(OS_BSD)
 
 // getDeviceData
 
