--- Plugins/CDIReader/cdilib.c.orig	2018-06-02 11:15:13.052742000 +0700
+++ Plugins/CDIReader/cdilib.c	2018-06-02 11:15:49.323204000 +0700
@@ -47,7 +47,7 @@
 #define _XOPEN_SOURCE 600
 #endif
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
   #include <unistd.h>
   #include <stdbool.h>
   #include <sys/types.h>
