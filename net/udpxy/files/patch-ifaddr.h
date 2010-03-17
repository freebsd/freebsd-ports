--- ifaddr.h.orig	2010-01-14 23:49:31.288490434 +0300
+++ ifaddr.h	2010-01-14 23:49:56.636770433 +0300
@@ -21,7 +21,7 @@
  */
 int
 if2addr( const char* ifname,
-         struct sockaddr *addr, size_t addrlen );
+         struct sockaddr_in *addr, size_t addrlen );
 
 
 /* convert input parameter into an IPv4-address string
