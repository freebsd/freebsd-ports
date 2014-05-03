--- ./net/base/mime_util_unittest.cc.orig	2014-04-24 22:35:53.000000000 +0200
+++ ./net/base/mime_util_unittest.cc	2014-04-24 23:23:46.000000000 +0200
@@ -260,7 +260,7 @@
     { "MeSsAge/*",  1, "eml" },
     { "image/bmp",  1, "bmp" },
     { "video/*",    6, "mp4" },
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_IOS)
+#if (defined(OS_POSIX) && !defined(OS_MACOSX)) || defined(OS_IOS)
     { "video/*",    6, "mpg" },
 #else
     { "video/*",    6, "mpeg" },
