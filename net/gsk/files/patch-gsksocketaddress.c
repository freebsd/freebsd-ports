--- src/gsksocketaddress.c.orig	Fri Aug 20 19:39:20 2004
+++ src/gsksocketaddress.c	Fri Aug 20 19:46:29 2004
@@ -184,7 +184,7 @@
 {
   GskSocketAddressIpv6 *ipv6 = GSK_SOCKET_ADDRESS_IPV6 (address);
   struct sockaddr_in6 *addr = output;
-  MAYBE_SET_LENGTH_MEMBER (addr->sinaddr->sin6_len, struct sockaddr_in6);
+  MAYBE_SET_LENGTH_MEMBER (addr->sin6_len, struct sockaddr_in6);
   addr->sin6_family = AF_INET6;
   addr->sin6_port = GUINT16_TO_BE (ipv6->port);
   addr->sin6_flowinfo = GUINT32_TO_BE (ipv6->flow_info);
