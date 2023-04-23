--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h.orig	2023-04-22 17:45:15 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h
@@ -10,7 +10,7 @@
 #include "chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
 #include "third_party/crashpad/crashpad/client/crash_report_database.h"
 #endif
 
@@ -29,7 +29,7 @@ class CrashReportingContext
   CrashReportingContext operator=(CrashReportingContext&&) = delete;
   ~CrashReportingContext() override;
 
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
   static CrashReportingContext* GetInstance();
 
   void AddProfile(BrowserCrashEventRouter* router, Profile* profile);
@@ -51,7 +51,7 @@ class CrashReportingContext
 #endif
 };
 
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
 
 // Utility function to parse reports from a crash database that were
 // created past a given timestamp. Included in header for testing.
