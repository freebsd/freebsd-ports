--- ui/base/clipboard/clipboard_constants.cc.orig	2020-11-16 14:58:44 UTC
+++ ui/base/clipboard/clipboard_constants.cc
@@ -16,11 +16,11 @@ const char kMimeTypeSvg[] = "image/svg+xml";
 const char kMimeTypeRTF[] = "text/rtf";
 const char kMimeTypePNG[] = "image/png";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if !defined(OS_APPLE)
 const char kMimeTypeWebCustomData[] = "chromium/x-web-custom-data";
