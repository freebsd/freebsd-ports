--- printing/print_settings_conversion.cc.orig	2022-08-31 12:19:35 UTC
+++ printing/print_settings_conversion.cc
@@ -256,7 +256,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && defined(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_CUPS))
   const base::Value::Dict* advanced_settings =
       job_settings.FindDict(kSettingAdvancedSettings);
   if (advanced_settings) {
