--- media/liboggz/include/oggz/oggz_off_t_generated.h.orig	2009-04-24 01:46:48.000000000 +0000
+++ media/liboggz/include/oggz/oggz_off_t_generated.h	2009-04-28 08:44:02.369576627 +0000
@@ -59,7 +59,7 @@
 
 #include <sys/types.h>
 
-#if defined(__APPLE__) || defined(SOLARIS)
+#if defined(__APPLE__) || defined(SOLARIS) || defined (__FreeBSD__)
 typedef off_t oggz_off_t;
 #else
 typedef loff_t oggz_off_t;
