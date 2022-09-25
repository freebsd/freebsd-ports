--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h
@@ -22,7 +22,7 @@ class BrowserCrashEventRouter
   BrowserCrashEventRouter& operator=(const BrowserCrashEventRouter&) = delete;
   ~BrowserCrashEventRouter() override;
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
   void OnCloudReportingLaunched(
       enterprise_reporting::ReportScheduler* report_scheduler) override;
 #endif  // !BUILDFLAG(IS_FUCHSIA)
@@ -32,7 +32,7 @@ class BrowserCrashEventRouter
       nullptr;
   raw_ptr<policy::ChromeBrowserCloudManagementController> controller_ = nullptr;
 
-#if !BUILDFLAG(IS_FUCHSIA)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD)
   // ReportCrashes() checks the enterprise policy settings, retrieves crash
   // reports from the crashpad local database and sends reports that have not
   // been sent to the reporting server.
