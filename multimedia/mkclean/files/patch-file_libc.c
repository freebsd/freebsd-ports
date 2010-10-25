--- corec/helpers/file/file_libc.c.orig	2010-09-26 04:42:30.000000000 -0700
+++ corec/helpers/file/file_libc.c	2010-10-24 01:44:37.000000000 -0700
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <errno.h>
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(__FreeBSD__)
 #include <sys/mount.h>
 #else
 #include <sys/vfs.h>
