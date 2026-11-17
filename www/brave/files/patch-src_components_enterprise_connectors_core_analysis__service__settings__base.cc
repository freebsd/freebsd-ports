--- src/components/enterprise/connectors/core/analysis_service_settings_base.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/enterprise/connectors/core/analysis_service_settings_base.cc
@@ -283,7 +283,7 @@ void AnalysisServiceSettingsBase::ParseV
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
