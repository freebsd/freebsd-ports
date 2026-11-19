--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -42,7 +42,7 @@
 #include "chrome/browser/enterprise/reporting/reporting_delegate_factory_desktop.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/browser_launch/browser_launch_event_controller_factory_desktop.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
@@ -136,7 +136,7 @@ void CloudProfileReportingService::CreateReportSchedul
         "profile", saas_usage_reporting_delegate_factory.get());
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Launch metadata should only be collected and uploaded once per browser
   // session, so do not recreate `browser_launch_controller_` if policy
   // reconnects mid-session.
