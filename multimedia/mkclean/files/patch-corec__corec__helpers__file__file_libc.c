--- ./corec/corec/helpers/file/file_libc.c.orig	2011-09-25 11:25:46.000000000 +0200
+++ ./corec/corec/helpers/file/file_libc.c	2011-09-28 16:25:02.262950715 +0200
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <errno.h>
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(TARGET_FREEBSD)
 #include <sys/mount.h>
 #else
 #include <sys/vfs.h>
