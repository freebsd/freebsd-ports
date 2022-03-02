--- ui/base/clipboard/clipboard_constants.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/base/clipboard/clipboard_constants.cc
@@ -22,7 +22,7 @@ const char kMimeTypePNG[] = "image/png";
 // Used for image drag & drop from LaCrOS.
 const char kMimeTypeOctetStream[] = "application/octet-stream";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
