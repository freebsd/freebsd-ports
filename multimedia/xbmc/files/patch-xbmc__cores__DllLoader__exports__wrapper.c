--- ./xbmc/cores/DllLoader/exports/wrapper.c.orig	2010-05-28 21:31:42.000000000 +0200
+++ ./xbmc/cores/DllLoader/exports/wrapper.c	2010-12-01 12:17:34.206576434 +0100
@@ -37,7 +37,7 @@
 #include <dirent.h>
 #endif
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 typedef int64_t   off64_t;
 typedef off_t     __off_t;
 typedef off64_t   __off64_t;
