--- printing/print_settings_conversion.cc.orig	2020-11-16 14:49:24 UTC
+++ printing/print_settings_conversion.cc
@@ -182,7 +182,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     return nullptr;
   }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::Optional<int> dpi_horizontal =
       job_settings.FindIntKey(kSettingDpiHorizontal);
   base::Optional<int> dpi_vertical =
@@ -212,14 +212,14 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
 #endif
   }
 
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(USE_CUPS))
+#if defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
   if (advanced_settings) {
     for (const auto& item : advanced_settings->DictItems())
       settings->advanced_settings().emplace(item.first, item.second.Clone());
   }
-#endif  // defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(USE_CUPS))
+#endif  // defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS))
 
 #if defined(OS_CHROMEOS)
   bool send_user_info =
