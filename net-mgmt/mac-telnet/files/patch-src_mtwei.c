--- src/mtwei.c.orig	2024-09-24 12:56:03 UTC
+++ src/mtwei.c
@@ -36,7 +36,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <libintl.h>
-#if defined(__linux__)
+#if defined(HAVE_SYS_RANDOM_H)
 #include <sys/random.h>
 #endif
 
