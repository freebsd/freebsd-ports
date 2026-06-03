--- components/enterprise/connectors/core/realtime_reporting_client_base.cc.orig	2026-04-09 06:05:42 UTC
+++ components/enterprise/connectors/core/realtime_reporting_client_base.cc
@@ -198,7 +198,7 @@ void RealtimeReportingClientBase::ReportEvent(
     *event.mutable_time() = ToProtoTimestamp(base::Time::Now());
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   MaybeCollectDeviceSignalsAndReportEvent(std::move(event), client, settings);
 #else
   // Regardless of collecting device signals or not, upload the security event
@@ -306,7 +306,7 @@ void RealtimeReportingClientBase::ReportEventWithTimes
   if (include_profile_user_name) {
     event.Set(kKeyProfileUserName, GetProfileUserName());
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   MaybeCollectDeviceSignalsAndReportEventDeprecated(std::move(event), client,
                                                     name, settings, time);
 #else
