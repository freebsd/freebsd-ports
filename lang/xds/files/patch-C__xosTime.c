--- C/xosTime.c.orig	2003-04-10 09:05:09.000000000 +0000
+++ C/xosTime.c	2007-01-24 15:12:15.000000000 +0000
@@ -78,7 +78,7 @@
         tzset();
 #endif
 
-#if defined(__FreeBSD__) || \
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) || \
     (defined(__ultrix) && !defined(SYSTEM_FIVE)) || \
     defined(DJGPP)
         res->zone = p->tm_gmtoff / 60;
