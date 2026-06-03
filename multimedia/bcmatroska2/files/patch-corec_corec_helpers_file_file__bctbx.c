--- corec/corec/helpers/file/file_bctbx.c.orig	2025-12-27 04:38:52 UTC
+++ corec/corec/helpers/file/file_bctbx.c
@@ -48,7 +48,7 @@
 // Do not move. Define TARGET_*.
 #include "file.h"
 
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(__FreeBSD__)
 #include <sys/mount.h>
 #elif defined(TARGET_QNX)
 #include <sys/statvfs.h>
