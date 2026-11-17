--- src/ui/base/clipboard/clipboard_constants.h.orig	2026-10-18 18:43:23 UTC
+++ src/ui/base/clipboard/clipboard_constants.h
@@ -46,7 +46,7 @@ inline constexpr char kMimeTypeWindowDra
 
 // ----- LINUX & CHROMEOS & FUCHSIA MIME TYPES -----
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 inline constexpr char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 inline constexpr char kMimeTypeLinuxString[] = "STRING";
 inline constexpr char kMimeTypeLinuxText[] = "TEXT";
@@ -59,7 +59,7 @@ inline constexpr char kMimeTypePortalFil
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kMimeTypeSourceUrl[] = "chromium/x-source-url";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
