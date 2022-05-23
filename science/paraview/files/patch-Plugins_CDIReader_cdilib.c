--- Plugins/CDIReader/cdilib.c.orig	2018-06-01 19:23:15 UTC
+++ Plugins/CDIReader/cdilib.c
@@ -47,7 +47,7 @@
 #define _XOPEN_SOURCE 600
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
   #include <unistd.h>
   #include <stdbool.h>
   #include <sys/types.h>
