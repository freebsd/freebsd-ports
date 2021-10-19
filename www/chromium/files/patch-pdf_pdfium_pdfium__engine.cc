--- pdf/pdfium/pdfium_engine.cc.orig	2021-09-24 04:26:09 UTC
+++ pdf/pdfium/pdfium_engine.cc
@@ -84,7 +84,7 @@
 #include "gin/public/cppgc.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -521,7 +521,7 @@ void InitializeSDK(bool enable_v8, FontMappingMode fon
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   g_font_mapping_mode = font_mapping_mode;
   InitializeLinuxFontMapper();
 #endif
