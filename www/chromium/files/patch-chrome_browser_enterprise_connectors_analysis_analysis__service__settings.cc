--- chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/enterprise/connectors/analysis/analysis_service_settings.cc
@@ -142,11 +142,11 @@ AnalysisServiceSettings::AnalysisServiceSettings(
   const char* verification_key = kKeyWindowsVerification;
 #elif BUILDFLAG(IS_MAC)
   const char* verification_key = kKeyMacVerification;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const char* verification_key = kKeyLinuxVerification;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::Value::Dict& dict = settings_value.GetDict();
   const base::Value::List* signatures =
       dict.FindListByDottedPath(verification_key);
