--- testing/test_avatars.c.orig	2014-09-24 03:00:12.000000000 +0200
+++ testing/test_avatars.c	2014-09-24 22:18:32.000000000 +0200
@@ -47,7 +47,11 @@
 #include <unistd.h>
 #include <time.h>
 #include <stdbool.h>
+#if defined(__linux__)
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <sys/syslimits.h>
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 #include <errno.h>
