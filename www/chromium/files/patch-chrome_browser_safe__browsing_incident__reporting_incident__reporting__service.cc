--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -709,7 +709,7 @@ void IncidentReportingService::OnEnvironmentDataCollec
 
 // Process::Current().CreationTime() is missing on some platforms.
 #if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
