--- StreamingProxy.tproj/proxy.c.orig	Sat Feb 10 04:02:08 2007
+++ StreamingProxy.tproj/proxy.c	Sat Feb 10 04:02:33 2007
@@ -203,7 +203,7 @@
 {
     int i, j;
     int     numOptions = 0; // num command line options spec'd
-    signed char ch;
+    int ch;
     int listening_port = 554, user_listener = false;
     time_t time_zero, now, last;
     time_t  usnow, uslast;
