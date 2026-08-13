--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -72,7 +72,7 @@
 #include "third_party/abseil-cpp/absl/functional/overload.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 
@@ -139,7 +139,7 @@ EmbedderKey CreateSidePanelEmbedderKey(tabs::TabInterf
 
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
