--- lib/net.c.orig	2015-01-27 23:18:59.000000000 -0500
+++ lib/net.c	2015-01-27 23:23:04.000000000 -0500
@@ -152,7 +152,11 @@
 
     snprintf (buf, sizeof(buf), "%d", port);
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    if ( (n = getaddrinfo("0.0.0.0", buf, &hints, &res) ) != 0) {
+#else
     if ( (n = getaddrinfo(NULL, buf, &hints, &res) ) != 0) {
+#endif
         ccnet_warning ("getaddrinfo fails: %s\n", gai_strerror(n));
         return -1;
     }
