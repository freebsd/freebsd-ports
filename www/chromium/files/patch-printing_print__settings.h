--- printing/print_settings.h.orig	2022-02-07 13:39:41 UTC
+++ printing/print_settings.h
@@ -18,7 +18,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -66,7 +66,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     }
   };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
@@ -221,7 +221,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -322,7 +322,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
