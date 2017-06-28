--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2017-06-05 19:03:03 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -720,7 +720,7 @@ void IncidentReportingService::OnEnvironmentDataCollec
   environment_collection_pending_ = false;
 
 // CurrentProcessInfo::CreationTime() is missing on some platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::CurrentProcessInfo::CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
