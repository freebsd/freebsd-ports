--- src/os/freebsd/xattr.c.orig	2018-08-10 21:04:37 UTC
+++ src/os/freebsd/xattr.c
@@ -27,8 +27,12 @@
 
 #include <os/freebsd/xattr.h>
 #include <sys/extattr.h>
+#include <sys/param.h>
 
+
+#ifndef EXTATTR_MAXNAMELEN
 #define EXTATTR_MAXNAMELEN 255
+#endif
 
 ssize_t fgetxattr(int fd, const char *name, void *value, size_t size)
 {
