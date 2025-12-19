--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc
@@ -25,7 +25,7 @@ const char kMimeTypeWindowDrag[] = "chromium/x-window-
 // Used for window dragging on some platforms.
 const char kMimeTypeWindowDrag[] = "chromium/x-window-drag";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
@@ -33,7 +33,7 @@ const char kMimeTypeLinuxText[] = "TEXT";
         // BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 const char kMimeTypeSourceUrl[] = "chromium/x-source-url";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_ANDROID)
