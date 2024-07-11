--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc
@@ -11,7 +11,7 @@ namespace enterprise_connectors {
 
 BrowserCrashEventRouter::BrowserCrashEventRouter(
     content::BrowserContext* context) {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   Profile* profile = Profile::FromBrowserContext(context);
@@ -21,7 +21,7 @@ BrowserCrashEventRouter::BrowserCrashEventRouter(
 }
 
 BrowserCrashEventRouter::~BrowserCrashEventRouter() {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   crash_reporting_context->RemoveProfile(this);
