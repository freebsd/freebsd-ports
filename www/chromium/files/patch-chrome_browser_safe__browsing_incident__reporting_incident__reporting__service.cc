--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2019-01-30 02:17:47.000000000 +0100
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc	2019-01-31 22:32:06.707636000 +0100
@@ -715,7 +715,7 @@
   environment_collection_pending_ = false;
 
 // Process::Current().CreationTime() is missing on some platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
