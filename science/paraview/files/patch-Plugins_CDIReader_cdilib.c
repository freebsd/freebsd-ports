--- Plugins/CDIReader/cdilib.c.orig	2016-11-14 15:41:57 UTC
+++ Plugins/CDIReader/cdilib.c
@@ -47,7 +47,7 @@
 #define _XOPEN_SOURCE 600
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
   #include <unistd.h>
   #include <stdbool.h>
   #include <sys/types.h>
