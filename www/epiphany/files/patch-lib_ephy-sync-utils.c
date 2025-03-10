--- lib/ephy-sync-utils.c.orig	2024-10-22 19:17:50 UTC
+++ lib/ephy-sync-utils.c
@@ -30,7 +30,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <webkit/webkit.h>
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/random.h>
 #elif defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <unistd.h>
