--- printing/print_settings.cc.orig	2021-09-24 04:26:09 UTC
+++ printing/print_settings.cc
@@ -283,9 +283,9 @@ void PrintSettings::Clear() {
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
