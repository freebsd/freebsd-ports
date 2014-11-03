--- lib/net.c.orig	2014-09-02 21:06:10.181095833 -0400
+++ lib/net.c	2014-09-02 21:06:40.052390263 -0400
@@ -154,7 +154,7 @@
 
     snprintf (buf, sizeof(buf), "%d", port);
 
-    if ( (n = getaddrinfo(NULL, buf, &hints, &res) ) != 0) {
+    if ( (n = getaddrinfo("0.0.0.0", buf, &hints, &res) ) != 0) {
         ccnet_warning ("getaddrinfo fails: %s\n", gai_strerror(n));
         return -1;
     }
