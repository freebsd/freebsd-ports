--- patch-src_network.c.orig	2017-10-28 15:54:22 UTC
+++ patch-src_network.c
@@ -0,0 +1,16 @@
+--- src/network.c.orig	2017-10-28 14:00:17 UTC
++++ src/network.c
+@@ -77,9 +77,13 @@ static void network_host_normalize_addr_
+     if (addr->plain.sa_family == AF_INET6)
+         buffer_append_string_len(host, CONST_STR_LEN("]"));
+     if (addr->plain.sa_family != AF_UNIX) {
++#ifdef HAVE_IPV6
+         unsigned short port = (addr->plain.sa_family == AF_INET)
+           ? ntohs(addr->ipv4.sin_port)
+           : ntohs(addr->ipv6.sin6_port);
++#elif
++	unsigned short port = ntohs(addr->ipv6.sin6_port);
++#endif
+         buffer_append_string_len(host, CONST_STR_LEN(":"));
+         buffer_append_int(host, (int)port);
+     }
