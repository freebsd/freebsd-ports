--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h
@@ -19,7 +19,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "components/policy/core/common/cloud/cloud_policy_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
 
@@ -95,7 +95,7 @@ class RealtimeReportingClient : public RealtimeReporti
       const std::string& dm_token) override;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   void MaybeCollectDeviceSignalsAndReportEvent(
       ::chrome::cros::reporting::proto::Event event,
       policy::CloudPolicyClient* client,
@@ -126,7 +126,7 @@ class RealtimeReportingClient : public RealtimeReporti
   base::WeakPtrFactory<RealtimeReportingClient> weak_ptr_factory_{this};
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AddCrowdstrikeSignalsToEvent(
     ::chrome::cros::reporting::proto::Event& event,
     const device_signals::SignalsAggregationResponse& response);
