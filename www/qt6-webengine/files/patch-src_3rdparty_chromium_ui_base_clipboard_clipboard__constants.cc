--- src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_constants.cc
@@ -24,7 +24,7 @@ const char kMimeTypeWindowDrag[] = "chromium/x-window-
 // Used for window dragging on some platforms.
 const char kMimeTypeWindowDrag[] = "chromium/x-window-drag";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
