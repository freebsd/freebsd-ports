--- printing/print_settings.h.orig	2023-03-13 07:33:08 UTC
+++ printing/print_settings.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -69,7 +69,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     }
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -234,7 +234,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -351,7 +351,7 @@ class COMPONENT_EXPORT(PRINTING) PrintSettings {
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
