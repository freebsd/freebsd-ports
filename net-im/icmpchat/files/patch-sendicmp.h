--- sendicmp.h.orig	2003-04-06 16:21:11 UTC
+++ sendicmp.h
@@ -16,6 +16,6 @@
 
 int sendpacket(int, const unsigned char *, const char *, int, int);
 int in_cksum(u_short *, int);
-struct sockaddr_in	saddr;
+extern struct sockaddr_in	saddr;
 
 #endif /* SENDICMP_H */
