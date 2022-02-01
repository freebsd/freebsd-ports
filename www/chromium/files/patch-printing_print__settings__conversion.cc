--- printing/print_settings_conversion.cc.orig	2021-12-14 11:45:09 UTC
+++ printing/print_settings_conversion.cc
@@ -220,7 +220,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
 #endif
   }
 
-#if defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(USE_CUPS))
+#if defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
   if (advanced_settings) {
@@ -232,7 +232,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
         settings->advanced_settings().emplace(item.first, item.second.Clone());
     }
   }
-#endif  // defined(OS_CHROMEOS) || (defined(OS_LINUX) && defined(USE_CUPS))
+#endif  // defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS))
 
 #if defined(OS_CHROMEOS)
   bool send_user_info =
