--- source/ni_rsrc_update.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_update.c
@@ -31,7 +31,7 @@
 #include <string.h>
 #include "ni_log.h"
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <unistd.h>
 #include <sys/types.h>
 #endif
@@ -44,7 +44,7 @@
 #ifdef _WIN32
 #include "ni_getopt.h"
 #define DEV_NAME_PREFIX "\\\\.\\Scsi"
-#elif __linux__
+#elif __linux__ || __FreeBSD__
 #define DEV_NAME_PREFIX "/dev/nvme"
 #elif __APPLE__
 #define DEV_NAME_PREFIX "/dev/disk"
