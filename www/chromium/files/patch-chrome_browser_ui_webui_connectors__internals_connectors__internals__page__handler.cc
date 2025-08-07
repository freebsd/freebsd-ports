--- chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/webui/connectors_internals/connectors_internals_page_handler.cc
@@ -82,7 +82,7 @@ connectors_internals::mojom::ClientIdentityPtr GetIden
 }
 #endif  // BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetStringFromTimestamp(base::Time timestamp) {
   return (timestamp == base::Time()) ? std::string()
                                      : base::UnlocalizedTimeFormatWithPattern(
@@ -191,7 +191,7 @@ void ConnectorsInternalsPageHandler::GetClientCertific
 
 void ConnectorsInternalsPageHandler::GetSignalsReportingState(
     GetSignalsReportingStateCallback callback) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile_prefs = profile_->GetPrefs();
 
   std::string last_upload_attempt_time_string =
