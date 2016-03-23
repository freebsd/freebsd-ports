--- xtrans-X11R7.0-1.0.0/Xtranssock.c.orig	2013-01-28 17:29:24.000000000 +0100
+++ xtrans-X11R7.0-1.0.0/Xtranssock.c	2016-02-14 17:33:06.948806000 +0100
@@ -286,11 +286,13 @@ static int TRANS(SocketINETClose) (Xtran
  * that don't have IPv6 support.
  */
 #if defined(IPv6) && defined(AF_INET6)
+#ifndef __FreeBSD__
 static const struct in6_addr local_in6addr_any = IN6ADDR_ANY_INIT;
 #pragma weak in6addr_any = local_in6addr_any
 #ifndef __USLC__
 #pragma weak getaddrinfo
 #endif
+#endif
 static int haveIPv6 = 1;
 #endif
 
