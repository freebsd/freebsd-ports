--- src/xxxprotocol.h.orig	2008-06-29 18:29:01.000000000 +0100
+++ src/xxxprotocol.h		2008-07-02 13:17:12.000000000 +0100
@@ -31,9 +31,9 @@
     uint port;
     int recvsd;		//UDP socket
     
-#ifdef BSD
+
     struct sockaddr_dl *search(u_long addr);
-#endif
+
     
     struct UserSpec {
 	char codec;
