--- media/liboggz/include/oggz/oggz_off_t_generated.h.orig	2010-09-06 11:33:54.000000000 +0200
+++ media/liboggz/include/oggz/oggz_off_t_generated.h	2010-09-06 11:34:16.000000000 +0200
@@ -59,7 +59,7 @@
 
 #include <sys/types.h>
 
-#if defined(__APPLE__) || defined(SOLARIS) || defined(OS2) || defined (_AIX)
+#if defined(__APPLE__) || defined(SOLARIS) || defined(OS2) || defined (_AIX) || defined (__FreeBSD__)
 typedef off_t oggz_off_t;
 #else
 typedef loff_t oggz_off_t;
