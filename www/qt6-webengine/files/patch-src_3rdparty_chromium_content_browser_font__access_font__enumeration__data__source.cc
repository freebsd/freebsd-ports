--- src/3rdparty/chromium/content/browser/font_access/font_enumeration_data_source.cc.orig	2023-11-03 10:09:45 UTC
+++ src/3rdparty/chromium/content/browser/font_access/font_enumeration_data_source.cc
@@ -16,7 +16,7 @@
 #include "content/browser/font_access/font_enumeration_data_source_win.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "content/browser/font_access/font_enumeration_data_source_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/font_access/font_enumeration_data_source_linux.h"
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -61,7 +61,7 @@ std::unique_ptr<FontEnumerationDataSource> FontEnumera
   return std::make_unique<FontEnumerationDataSourceWin>();
 #elif BUILDFLAG(IS_APPLE)
   return std::make_unique<FontEnumerationDataSourceMac>();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<FontEnumerationDataSourceLinux>();
 #else
   return std::make_unique<FontEnumerationDataSourceNull>();
@@ -76,7 +76,7 @@ bool FontEnumerationDataSource::IsOsSupported() {
   return true;
 #elif BUILDFLAG(IS_APPLE)
   return true;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
