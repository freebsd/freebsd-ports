--- media/liboggz/include/oggz/oggz_off_t_generated.h.orig	2009-08-24 17:52:50.000000000 +0200
+++ media/liboggz/include/oggz/oggz_off_t_generated.h	2009-09-10 15:26:59.000000000 +0200
@@ -59,7 +59,7 @@
 
 #include <sys/types.h>
 
-#if defined(__APPLE__) || defined(SOLARIS) || defined(OS2)
+#if defined(__APPLE__) || defined(SOLARIS) || defined(OS2) || defined(__FreeBSD__)
 typedef off_t oggz_off_t;
 #else
 typedef loff_t oggz_off_t;
