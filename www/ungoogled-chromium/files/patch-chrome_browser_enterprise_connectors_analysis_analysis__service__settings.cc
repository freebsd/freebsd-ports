--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -192,7 +192,7 @@ void AnalysisServiceSettings::ParseVerificationSignatu
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
