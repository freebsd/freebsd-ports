--- printing/print_settings.cc.orig	2022-02-07 13:39:41 UTC
+++ printing/print_settings.cc
@@ -265,7 +265,7 @@ PrintSettings::PrintSettings(const PrintSettings& sett
 #endif
   is_modifiable_ = settings.is_modifiable_;
   pages_per_sheet_ = settings.pages_per_sheet_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (const auto& item : settings.advanced_settings_)
     advanced_settings_.emplace(item.first, item.second.Clone());
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -305,7 +305,7 @@ PrintSettings& PrintSettings::operator=(const PrintSet
 #endif
   is_modifiable_ = settings.is_modifiable_;
   pages_per_sheet_ = settings.pages_per_sheet_;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   for (const auto& item : settings.advanced_settings_)
     advanced_settings_.emplace(item.first, item.second.Clone());
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -345,7 +345,7 @@ void PrintSettings::Clear() {
 #endif
   is_modifiable_ = true;
   pages_per_sheet_ = 1;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   advanced_settings_.clear();
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 #if defined(OS_CHROMEOS)
