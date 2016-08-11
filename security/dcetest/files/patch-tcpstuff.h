--- tcpstuff.h.orig	2001-08-20 20:29:56 UTC
+++ tcpstuff.h
@@ -42,5 +42,7 @@ make_tcp_listener(unsigned short localpo
 int
 write_uint32(int fd,uint32 data);
 
+/* This is not used and gives a warning in FreeBSD's ports system
 int
 tcp_accept(int listenFd);
+*/
