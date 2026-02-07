--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.h
@@ -41,7 +41,7 @@ extern const char kMimeTypeWindowDrag[];
 
 // ----- LINUX & CHROMEOS & FUCHSIA MIME TYPES -----
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
 extern const char kMimeTypeLinuxUtf8String[];
 COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
@@ -53,7 +53,7 @@ COMPONENT_EXPORT(UI_BASE_CLIPBOARD_TYPES)
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 extern const char kMimeTypeSourceUrl[];
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
