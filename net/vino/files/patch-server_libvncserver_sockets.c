Index: server/libvncserver/sockets.c
diff -u -p server/libvncserver/sockets.c.orig server/libvncserver/sockets.c
--- server/libvncserver/sockets.c.orig	Tue Jan  2 22:34:50 2007
+++ server/libvncserver/sockets.c	Sun Mar 25 22:52:02 2007
@@ -560,6 +560,7 @@ ListenOnTCPPort(port, localOnly)
 
 #ifdef ENABLE_IPV6
     struct sockaddr_in6 addr_in6;
+    int off = 0;
 
     memset(&addr_in6, 0, sizeof(addr_in6));
     addr_in6.sin6_family = AF_INET6;
@@ -570,6 +571,9 @@ ListenOnTCPPort(port, localOnly)
     addrlen = sizeof(addr_in6);
 
     sock = socket(AF_INET6, SOCK_STREAM, 0);
+#ifdef IPV6_V6ONLY
+    setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof(off));
+#endif
 #endif
 
     if (sock < 0) {
