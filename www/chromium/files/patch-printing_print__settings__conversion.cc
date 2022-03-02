--- printing/print_settings_conversion.cc.orig	2022-02-28 16:54:41 UTC
+++ printing/print_settings_conversion.cc
@@ -216,7 +216,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && defined(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
   if (advanced_settings) {
