--- components/enterprise/connectors/core/realtime_reporting_client_base.cc.orig	2026-11-11 14:44:17 UTC
+++ components/enterprise/connectors/core/realtime_reporting_client_base.cc
@@ -202,7 +202,7 @@ void RealtimeReportingClientBase::ReportEvent(
     *event.mutable_time() = ToProtoTimestamp(base::Time::Now());
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeCollectDeviceSignalsAndReportEvent(std::move(event), client, settings);
 #else
   // Regardless of collecting device signals or not, upload the security event
