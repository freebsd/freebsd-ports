--- server/msgidd.c.orig	Fri Dec  9 03:53:01 1994
+++ server/msgidd.c	Thu Dec 14 10:48:45 2006
@@ -34,8 +34,10 @@
 #define dprintf (void)
 #endif
 
+#ifndef __FreeBSD__
 char *malloc();
 extern int errno;
+#endif
 
 int log = 0, flags = 0;
 time_t hold_time = MAX_AGE * 60;
@@ -171,7 +173,7 @@
     alarm(ALARM_TIME);
 }
 
-SIGRET onpipe();
+static SIGRET onpipe();
 
 main(argc, argv)
     int argc;
