--- StreamingProxy.tproj/proxy.c.orig	2008-05-06 08:28:57.000000000 +0900
+++ StreamingProxy.tproj/proxy.c	2008-06-01 18:10:57.000000000 +0900
@@ -204,7 +204,7 @@
 {
     int i, j;
     int     numOptions = 0; // num command line options spec'd
-    signed char ch;
+    int ch;
     int listening_port = 554, user_listener = false;
     time_t time_zero, now, last;
     time_t  usnow, uslast;
