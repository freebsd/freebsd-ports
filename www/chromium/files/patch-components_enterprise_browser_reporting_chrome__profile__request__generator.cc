--- components/enterprise/browser/reporting/chrome_profile_request_generator.cc.orig	2026-11-19 12:25:27 UTC
+++ components/enterprise/browser/reporting/chrome_profile_request_generator.cc
@@ -214,7 +214,7 @@ void ChromeProfileRequestGenerator::OnBaseReportsReady
   signals_request.signal_names.emplace(device_signals::SignalName::kHotfixes);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (enterprise_signals::features::IsCertificateCollectionEnabled() &&
       generation_config.challenge.has_value() &&
       !generation_config.challenge.value().empty()) {
