--- server/msgidd.c.orig	Fri Dec  9 03:53:01 1994
+++ server/msgidd.c	Mon Nov  4 05:51:18 2002
@@ -34,8 +34,10 @@
 #define dprintf (void)
 #endif
 
+#ifndef __FreeBSD__
 char *malloc();
 extern int errno;
+#endif
 
 int log = 0, flags = 0;
 time_t hold_time = MAX_AGE * 60;
