--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc
@@ -29,7 +29,7 @@
 #include "components/enterprise/connectors/core/reporting_constants.h"
 #include "google_apis/gaia/gaia_id.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <optional>
 
 #include "base/strings/string_util.h"
@@ -324,7 +324,7 @@ api::enterprise_reporting_private::ContextInfo ToConte
 }
 
 bool AllowClientCertificateReportingForUsers() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       enterprise_signals::features::kAllowClientCertificateReportingForUsers);
 #else
@@ -337,7 +337,7 @@ bool IsProfilePrefManaged(Profile* profile, std::strin
   return pref && pref->IsManaged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 device_signals::SignalsAggregationRequest CreateAggregationRequest(
     device_signals::SignalName signal_name) {
@@ -399,7 +399,7 @@ EnterpriseReportingPrivateGetDeviceIdFunction::
 
 // getPersistentSecret
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 EnterpriseReportingPrivateGetPersistentSecretFunction::
     EnterpriseReportingPrivateGetPersistentSecretFunction() = default;
@@ -716,7 +716,7 @@ void EnterpriseReportingPrivateGetCertificateFunction:
   Respond(WithArguments(ret.ToValue()));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // getFileSystemInfo
 
