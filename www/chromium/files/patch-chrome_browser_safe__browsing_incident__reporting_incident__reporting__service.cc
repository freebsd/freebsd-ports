--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2020-11-13 06:36:37 UTC
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -676,7 +676,7 @@ void IncidentReportingService::OnEnvironmentDataCollec
   environment_collection_pending_ = false;
 
 // Process::Current().CreationTime() is missing on some platforms.
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
