--- printing/print_settings.h.orig	2020-09-08 19:14:09 UTC
+++ printing/print_settings.h
@@ -20,7 +20,7 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/size.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -69,7 +69,7 @@
     }
   };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // defined(OS_LINUX)
 
@@ -206,7 +206,7 @@
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -305,7 +305,7 @@
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // defined(OS_LINUX)
