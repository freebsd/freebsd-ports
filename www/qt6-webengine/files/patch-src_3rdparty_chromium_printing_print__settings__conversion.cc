--- src/3rdparty/chromium/printing/print_settings_conversion.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/printing/print_settings_conversion.cc
@@ -215,7 +215,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && defined(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_CUPS))
   const base::Value::Dict* advanced_settings =
       job_settings.FindDict(kSettingAdvancedSettings);
   if (advanced_settings) {
