--- src/local.c.orig	Tue May  6 07:50:38 1997
+++ src/local.c	Sat Nov  2 14:52:00 2002
@@ -26,7 +26,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#if defined(SYSV) || defined(SVR4) || defined(__arm)
+#if defined(SYSV) || defined(SVR4) || defined(__arm) || defined(__FreeBSD__)
 #include <dirent.h>
 #define DIRSTUFF struct dirent
 #else
