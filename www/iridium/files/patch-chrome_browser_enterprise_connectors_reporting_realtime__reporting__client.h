--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h
@@ -19,7 +19,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "components/policy/core/common/cloud/cloud_policy_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
 
@@ -119,7 +119,7 @@ class RealtimeReportingClient : public RealtimeReporti
       const std::string& dm_token) override;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   // DEPRECATED: Use MaybeCollectDeviceSignalsAndReportEvent(Event, ...).
   void MaybeCollectDeviceSignalsAndReportEventDeprecated(
       base::Value::Dict event,
@@ -169,7 +169,7 @@ class RealtimeReportingClient : public RealtimeReporti
   base::WeakPtrFactory<RealtimeReportingClient> weak_ptr_factory_{this};
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Populate event dict with CrowdStrike signal values. If those signals are
 // available in `response`, this function returns a Dict with the following
 // fields added:
