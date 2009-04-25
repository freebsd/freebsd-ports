--- media/liboggz/include/oggz/oggz_off_t_generated.h.orig	2008-11-24 21:01:48.000000000 +0000
+++ media/liboggz/include/oggz/oggz_off_t_generated.h	2008-11-24 21:16:57.000000000 +0000
@@ -59,7 +59,7 @@
 
 #include <sys/types.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined (__FreeBSD__)
 typedef off_t oggz_off_t;
 #else
 typedef loff_t oggz_off_t;
