--- net/base/mime_util_unittest.cc.orig	2015-09-26 19:23:37.646612000 +0200
+++ net/base/mime_util_unittest.cc	2015-09-26 19:24:04.566580000 +0200
@@ -242,7 +242,7 @@
     { "MeSsAge/*",  1, "eml" },
     { "image/bmp",  1, "bmp" },
     { "video/*",    6, "mp4" },
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_IOS)
+#if (defined(OS_POSIX) && !defined(OS_MACOSX)) || defined(OS_IOS)
     { "video/*",    6, "mpg" },
 #else
     { "video/*",    6, "mpeg" },
