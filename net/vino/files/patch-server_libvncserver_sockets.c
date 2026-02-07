--- server/libvncserver/sockets.c.orig	2009-02-13 08:11:38.000000000 -0500
+++ server/libvncserver/sockets.c	2009-03-07 20:19:28.000000000 -0500
@@ -668,6 +669,11 @@ NewSocketListenTCP(struct sockaddr *addr
 {
     int sock = -1;
     int one  = 1;
+#ifdef ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+    int off = 0;
+#endif
+#endif
 
     if ((sock = socket(addr->sa_family, SOCK_STREAM, 0)) < 0)
       return -1;
@@ -677,6 +683,15 @@ NewSocketListenTCP(struct sockaddr *addr
       return -1;
     }
 
+#ifdef  ENABLE_IPV6
+#ifdef IPV6_V6ONLY
+    if (setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof(off)) < 0) {
+      close(sock);
+      return -1;
+    }
+#endif
+#endif
+
     if (bind(sock, addr, len) < 0) {
       close(sock);
       return -1;
