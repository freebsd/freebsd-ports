--- net/base/mime_util_unittest.cc.orig	2013-09-02 22:31:36.000000000 +0300
+++ net/base/mime_util_unittest.cc	2013-09-02 22:32:33.000000000 +0300
@@ -245,7 +245,7 @@
     { "MeSsAge/*",  1, "eml" },
     { "image/bmp",  1, "bmp" },
     { "video/*",    6, "mp4" },
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_IOS)
+#if (defined(OS_POSIX) && !defined(OS_MACOSX)) || defined(OS_IOS)
     { "video/*",    6, "mpg" },
 #else
     { "video/*",    6, "mpeg" },
