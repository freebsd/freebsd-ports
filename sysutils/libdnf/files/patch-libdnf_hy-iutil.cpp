--- libdnf/hy-iutil.cpp.orig	2020-09-20 22:51:04 UTC
+++ libdnf/hy-iutil.cpp
@@ -22,7 +22,9 @@
 #include <errno.h>
 #include <dirent.h>
 #include <fcntl.h>
+#if !defined(__FreeBSD__)
 #include <linux/limits.h>
+#endif
 #include <pwd.h>
 #include <unistd.h>
 #include <stdio.h>
