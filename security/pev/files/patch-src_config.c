--- src/config.c.orig	2017-01-06 22:27:18 UTC
+++ src/config.c
@@ -40,7 +40,7 @@
 #include <string.h>
 #if defined(__linux__)
 #include <linux/limits.h>
-#elif defined(__NetBSD__)
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
 #include <limits.h>
 #elif defined(__APPLE__)
 #include <sys/syslimits.h>
