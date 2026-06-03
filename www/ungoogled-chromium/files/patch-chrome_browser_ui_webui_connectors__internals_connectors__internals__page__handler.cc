--- chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc.orig	2026-05-09 18:09:27 UTC
+++ chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc
@@ -75,7 +75,7 @@ std::string ConvertPolicyLevelToString(DTCPolicyLevel 
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 std::string GetStringFromTimestamp(base::Time timestamp) {
   return (timestamp == base::Time()) ? std::string()
                                      : base::UnlocalizedTimeFormatWithPattern(
@@ -190,7 +190,7 @@ void ConnectorsInternalsPageHandler::GetClientCertific
 void ConnectorsInternalsPageHandler::GetSignalsReportingState(
     GetSignalsReportingStateCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* profile_prefs = profile_->GetPrefs();
 
   std::string last_upload_attempt_time_string =
@@ -331,7 +331,7 @@ void ConnectorsInternalsPageHandler::OnSignalsCollecte
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void ConnectorsInternalsPageHandler::OnReportGenerated(
     GetSignalsReportingStateCallback callback,
     connectors_internals::mojom::SignalsReportingStatePtr state,
