--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -41,7 +41,7 @@
 #include "chrome/browser/enterprise/reporting/reporting_delegate_factory_desktop.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/browser_launch/browser_launch_event_controller_factory_desktop.h"
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_delegate_factory_desktop.h"
 #include "components/enterprise/browser/reporting/reporting_features.h"
@@ -124,7 +124,7 @@ void CloudProfileReportingService::CreateReportSchedul
 #endif
   report_scheduler_ = std::make_unique<ReportScheduler>(std::move(params));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kSaasUsageReporting)) {
     auto saas_usage_reporting_delegate_factory =
         SaasUsageReportingDelegateFactoryDesktop::CreateForProfile(profile_);
