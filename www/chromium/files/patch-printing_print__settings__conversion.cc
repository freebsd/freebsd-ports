--- printing/print_settings_conversion.cc.orig	2021-04-14 18:41:07 UTC
+++ printing/print_settings_conversion.cc
@@ -213,8 +213,8 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_CHROMEOS) ||                                  \
-    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if defined(OS_CHROMEOS) ||                                                     \
+    ((defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
      defined(USE_CUPS))
   const base::Value* advanced_settings =
       job_settings.FindDictKey(kSettingAdvancedSettings);
@@ -222,7 +222,7 @@ std::unique_ptr<PrintSettings> PrintSettingsFromJobSet
     for (const auto& item : advanced_settings->DictItems())
       settings->advanced_settings().emplace(item.first, item.second.Clone());
   }
-#endif  // defined(OS_CHROMEOS) || ((defined(OS_LINUX) ||
+#endif  // defined(OS_CHROMEOS) || ((defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) && defined(USE_CUPS))
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
