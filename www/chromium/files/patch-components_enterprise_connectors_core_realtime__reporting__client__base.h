--- components/enterprise/connectors/core/realtime_reporting_client_base.h.orig	2026-11-11 14:44:17 UTC
+++ components/enterprise/connectors/core/realtime_reporting_client_base.h
@@ -115,7 +115,7 @@ class RealtimeReportingClientBase : public KeyedServic
   // on Windows/Mac/Linux platforms. Regardless of collecting device signals or
   // not, this method is expected to call `UploadSecurityEvent()` in the
   // end.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   virtual void MaybeCollectDeviceSignalsAndReportEvent(
       ::chrome::cros::reporting::proto::Event event,
