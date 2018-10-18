--- corec/corec/helpers/file/file_libc.c.orig	2017-07-20 13:52:29 UTC
+++ corec/corec/helpers/file/file_libc.c
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <errno.h>
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(__FreeBSD__)
 #include <sys/mount.h>
 #elif defined(TARGET_QNX)
 #include <sys/statvfs.h>
