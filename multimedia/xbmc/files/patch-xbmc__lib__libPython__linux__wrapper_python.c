--- ./xbmc/lib/libPython/linux/wrapper_python.c.orig	2010-07-17 23:26:42.000000000 +0200
+++ ./xbmc/lib/libPython/linux/wrapper_python.c	2010-12-01 12:17:34.245845263 +0100
@@ -40,7 +40,7 @@
 int xbp_mkdir(const char *dirname);
 int xbp_open(const char *filename, int oflag, int pmode);
 int xbp_lstat(const char * path, struct stat * buf);
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 int xbp_lstat64(const char * path, struct stat64 * buf);
 #endif
 void *xbp_dlopen(const char *filename, int flag);
@@ -98,7 +98,7 @@
 {
   return xbp_lstat(path, buf);
 }
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 int PYTHON_WRAP(lstat64)(const char * path, struct stat64 * buf)
 {
   return xbp_lstat64(path, buf);
