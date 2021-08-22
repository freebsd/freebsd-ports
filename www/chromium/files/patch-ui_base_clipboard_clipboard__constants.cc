--- ui/base/clipboard/clipboard_constants.cc.orig	2021-07-19 18:45:43 UTC
+++ ui/base/clipboard/clipboard_constants.cc
@@ -20,11 +20,11 @@ const char kMimeTypePNG[] = "image/png";
 // Used for image drag & drop from LaCrOS.
 const char kMimeTypeOctetStream[] = "application/octet-stream";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 #if !defined(OS_APPLE)
 const char kMimeTypeWebCustomData[] = "chromium/x-web-custom-data";
