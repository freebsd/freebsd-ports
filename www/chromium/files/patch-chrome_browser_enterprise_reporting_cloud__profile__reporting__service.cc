--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -39,7 +39,7 @@
 #include "chrome/browser/enterprise/reporting/reporting_delegate_factory_desktop.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/browser_launch/browser_launch_event_controller_factory_desktop.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
@@ -126,7 +126,7 @@ void CloudProfileReportingService::CreateReportSchedul
         "profile", saas_usage_reporting_delegate_factory.get());
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kBrowserLaunchMetadataReporting)) {
     browser_launch_controller_ =
         BrowserLaunchEventControllerFactoryDesktop::CreateForProfile(profile_);
