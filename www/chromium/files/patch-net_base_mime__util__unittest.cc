--- net/base/mime_util_unittest.cc.orig	2017-06-05 19:03:09 UTC
+++ net/base/mime_util_unittest.cc
@@ -250,7 +250,7 @@ TEST(MimeUtilTest, TestGetExtensionsForMimeType) {
     {"message/", 0, NULL, true},
     {"image/bmp", 1, "bmp"},
     {"video/*", 6, "mp4"},
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_IOS)
+#if (defined(OS_POSIX) && !defined(OS_MACOSX)) || defined(OS_IOS)
     {"video/*", 6, "mpg"},
 #else
     {"video/*", 6, "mpeg"},
