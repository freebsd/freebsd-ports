--- src/cache.c.orig	Fri Apr 18 20:18:36 1997
+++ src/cache.c	Sat Nov  2 14:50:53 2002
@@ -28,7 +28,7 @@
 #include <sys/param.h>
 #include <fcntl.h>
 
-#if defined(SYSV) || defined(SVR4)|| defined(__arm)
+#if defined(SYSV) || defined(SVR4)|| defined(__arm) || defined(__FreeBSD__)
 #include <dirent.h>
 #define DIRSTUFF struct dirent
 #else
