--- src/cookie-jar.c.orig	2010-11-29 21:00:58.000000000 +0100
+++ src/cookie-jar.c	2010-11-29 21:01:17.000000000 +0100
@@ -211,7 +211,7 @@
     sa.sun_family = AF_UNIX;
 
     /* create socket file descriptor and connect it to path */
-    fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
+    fd = socket(AF_UNIX, SOCK_STREAM, 0);
     if(fd == -1) {
         g_printerr("connect_cookie_socket: creating socket failed (%s)\n", strerror(errno));
         return;
