--- tcpstuff.h.orig	Sat Jan 11 06:48:15 2003
+++ tcpstuff.h	Sat Jan 11 06:48:54 2003
@@ -42,5 +42,7 @@
 int
 write_uint32(int fd,uint32 data);
 
+/* This is not used and gives a warning in FreeBSD's ports system
 int
 tcp_accept(int listenFd);
+*/
