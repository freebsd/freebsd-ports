--- printing/print_settings.cc.orig	2021-12-14 11:45:09 UTC
+++ printing/print_settings.cc
@@ -266,10 +266,10 @@ PrintSettings::PrintSettings(const PrintSettings& sett
 #endif
   is_modifiable_ = settings.is_modifiable_;
   pages_per_sheet_ = settings.pages_per_sheet_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (const auto& item : settings.advanced_settings_)
     advanced_settings_.emplace(item.first, item.second.Clone());
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   send_user_info_ = settings.send_user_info_;
   username_ = settings.username_;
@@ -307,10 +307,10 @@ PrintSettings& PrintSettings::operator=(const PrintSet
 #endif
   is_modifiable_ = settings.is_modifiable_;
   pages_per_sheet_ = settings.pages_per_sheet_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (const auto& item : settings.advanced_settings_)
     advanced_settings_.emplace(item.first, item.second.Clone());
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   send_user_info_ = settings.send_user_info_;
   username_ = settings.username_;
@@ -348,9 +348,9 @@ void PrintSettings::Clear() {
 #endif
   is_modifiable_ = true;
   pages_per_sheet_ = 1;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   advanced_settings_.clear();
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(OS_CHROMEOS)
   send_user_info_ = false;
   username_.clear();
