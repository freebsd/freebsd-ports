--- corec/corec/helpers/file/file_libc.c.orig	2012-12-16 10:29:34 UTC
+++ corec/corec/helpers/file/file_libc.c
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <errno.h>
-#if defined(TARGET_OSX)
+#if defined(TARGET_OSX) || defined(TARGET_FREEBSD)
 #include <sys/mount.h>
 #else
 #include <sys/vfs.h>
