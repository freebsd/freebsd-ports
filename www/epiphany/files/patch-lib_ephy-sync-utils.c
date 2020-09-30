--- lib/ephy-sync-utils.c.orig	2020-09-11 23:16:40 UTC
+++ lib/ephy-sync-utils.c
@@ -30,9 +30,9 @@
 #include <libsoup/soup.h>
 #include <stdio.h>
 #include <string.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/random.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
 #include <unistd.h>
 #endif
 
