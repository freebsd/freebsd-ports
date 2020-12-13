--- wolfssh/test.h.orig	2020-08-31 18:13:34 UTC
+++ wolfssh/test.h
@@ -436,8 +436,8 @@ static INLINE void build_addr(SOCKADDR_IN_T* addr, con
             memset(&hints, 0, sizeof(hints));
 
             hints.ai_family   = AF_INET_V;
-            hints.ai_socktype = udp ? SOCK_DGRAM : SOCK_STREAM;
-            hints.ai_protocol = udp ? IPPROTO_UDP : IPPROTO_TCP;
+            hints.ai_socktype = 1 ? SOCK_DGRAM : SOCK_STREAM;
+            hints.ai_protocol = 1 ? IPPROTO_UDP : IPPROTO_TCP;
 
             WSNPRINTF(strPort, sizeof(strPort), "%d", port);
             strPort[79] = '\0';
