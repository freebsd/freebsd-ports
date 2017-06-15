--- lib/net.c.orig	2016-10-09 09:30:49 UTC
+++ lib/net.c
@@ -157,7 +157,11 @@ ccnet_net_bind_tcp (int port, int nonblo
 
     snprintf (buf, sizeof(buf), "%d", port);
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    if ( (n = getaddrinfo("0.0.0.0", buf, &hints, &res) ) != 0) {
+#else
     if ( (n = getaddrinfo(NULL, buf, &hints, &res) ) != 0) {
+#endif
         ccnet_warning ("getaddrinfo fails: %s\n", gai_strerror(n));
         return -1;
     }
