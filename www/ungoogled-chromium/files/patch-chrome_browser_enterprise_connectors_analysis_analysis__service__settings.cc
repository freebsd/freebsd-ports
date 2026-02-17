--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -54,7 +54,7 @@ void AnalysisServiceSettings::ParseVerificationSignatu
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
