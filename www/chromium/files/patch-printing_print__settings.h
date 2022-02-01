--- printing/print_settings.h.orig	2021-12-14 11:45:09 UTC
+++ printing/print_settings.h
@@ -18,11 +18,11 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <map>
 
 #include "base/values.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 namespace printing {
 
@@ -66,9 +66,9 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     }
   };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   PrintSettings();
   PrintSettings(const PrintSettings&);
@@ -224,12 +224,12 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   void set_send_user_info(bool send_user_info) {
@@ -328,10 +328,10 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   // Whether to send user info.
