--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -85,7 +85,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 
@@ -152,7 +152,7 @@ constexpr auto kImplicitInvocationSources =
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
