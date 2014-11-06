--- lib/net.c.orig	2014-09-02 21:09:59.708953392 -0400
+++ lib/net.c	2014-09-02 21:10:22.959507209 -0400
@@ -157,7 +157,7 @@
 
     snprintf (buf, sizeof(buf), "%d", port);
 
-    if ( (n = getaddrinfo(NULL, buf, &hints, &res) ) != 0) {
+    if ( (n = getaddrinfo("0.0.0.0", buf, &hints, &res) ) != 0) {
         ccnet_warning ("getaddrinfo fails: %s\n", gai_strerror(n));
         return -1;
     }
