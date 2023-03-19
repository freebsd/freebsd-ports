--- corec/corec/helpers/file/file_libc.c.orig	2022-11-29 10:25:07 UTC
+++ corec/corec/helpers/file/file_libc.c
@@ -44,7 +44,7 @@
 // Do not move. Define TARGET_*.
 #include "file.h"
 
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(__FreeBSD__)
 #include <sys/mount.h>
 #elif defined(TARGET_QNX)
 #include <sys/statvfs.h>
