--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.cc
@@ -53,7 +53,7 @@
 #include "base/strings/utf_string_conversions.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/device_signals/core/browser/signals_aggregator.h"
@@ -62,7 +62,7 @@
 
 namespace enterprise_connectors {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 using Event = ::chrome::cros::reporting::proto::Event;
 #endif
 
@@ -144,7 +144,7 @@ RealtimeReportingClient::GetReportingSettings() {
 }
 
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 
 void AddCrowdstrikeSignalsToEvent(
@@ -248,7 +248,7 @@ std::string RealtimeReportingClient::GetProfileUserNam
   username_ =
       identity_manager_ ? GetProfileEmail(identity_manager_) : std::string();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (username_.empty()) {
     username_ = Profile::FromBrowserContext(context_)->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
@@ -305,7 +305,7 @@ std::string RealtimeReportingClient::GetBrowserClientI
   return client_id;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
 void RealtimeReportingClient::MaybeCollectDeviceSignalsAndReportEvent(
     Event event,
     policy::CloudPolicyClient* client,
