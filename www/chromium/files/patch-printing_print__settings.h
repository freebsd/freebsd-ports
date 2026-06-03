--- printing/print_settings.h.orig	2026-02-11 09:05:39 UTC
+++ printing/print_settings.h
@@ -25,7 +25,7 @@
 #include "base/values.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -52,7 +52,7 @@ inline constexpr char kMacSystemPrintDialogDataPrintSe
     "print_settings";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Used by PrintDialogGtk
 inline constexpr char kLinuxSystemPrintDialogDataPrinter[] = "printer_name";
 inline constexpr char kLinuxSystemPrintDialogDataPrintSettings[] =
@@ -112,7 +112,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS) PrintSetting
     std::string vendor_id;
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -300,7 +300,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS) PrintSetting
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -461,7 +461,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS) PrintSetting
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
