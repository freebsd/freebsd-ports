--- components/enterprise/connectors/core/realtime_reporting_client_base.cc.orig	2026-09-25 15:26:43 UTC
+++ components/enterprise/connectors/core/realtime_reporting_client_base.cc
@@ -196,7 +196,7 @@ void RealtimeReportingClientBase::ReportEvent(
     *event.mutable_time() = ToProtoTimestamp(base::Time::Now());
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   MaybeCollectDeviceSignalsAndReportEvent(std::move(event), client, settings);
 #else
   // Regardless of collecting device signals or not, upload the security event
