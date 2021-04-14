--- libdnf/hy-iutil.cpp.orig	2021-04-12 15:10:19 UTC
+++ libdnf/hy-iutil.cpp
@@ -22,7 +22,7 @@
 #include <errno.h>
 #include <dirent.h>
 #include <fcntl.h>
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <limits.h>
 #else
 #include <linux/limits.h>
