--- lib/ephy-sync-utils.c.orig	2021-09-28 21:57:11 UTC
+++ lib/ephy-sync-utils.c
@@ -30,9 +30,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <webkit2/webkit2.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/random.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
 #include <unistd.h>
 #endif
 
