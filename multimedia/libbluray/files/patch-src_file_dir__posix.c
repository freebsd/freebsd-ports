--- src/file/dir_posix.c.orig	2022-11-26 05:45:24.000000000 -0800
+++ src/file/dir_posix.c	2025-09-11 07:58:04.802880000 -0700
@@ -26,6 +26,8 @@
 #include "util/logging.h"
 #include "util/strutl.h"
 
+#include <sys/param.h>
+
 #include <stdlib.h>
 #include <string.h>
 #if defined(HAVE_DIRENT_H)
@@ -74,7 +76,11 @@
     int result;
     struct dirent e;
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1600000
+    result = (int)readdir((DIR*)dir->internal);
+#else
     result = readdir_r((DIR*)dir->internal, &e, &p_e);
+#endif
     if (result) {
         _error("Error reading directory", result, dir);
         return -result;
