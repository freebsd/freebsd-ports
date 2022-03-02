--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc
@@ -155,7 +155,7 @@ EnterpriseReportingPrivateGetDeviceIdFunction::
 
 // getPersistentSecret
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 EnterpriseReportingPrivateGetPersistentSecretFunction::
     EnterpriseReportingPrivateGetPersistentSecretFunction() = default;
