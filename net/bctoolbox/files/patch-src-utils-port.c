--- src/utils/port.c.orig	2017-07-17 12:16:03 UTC
+++ src/utils/port.c
@@ -1331,7 +1331,7 @@ void bctbx_sockaddr_remove_nat64_mapping(const struct 
 		if (htonl(0x0064ff9b) ==
 #ifdef _MSC_VER
 			((in6->sin6_addr.u.Word[0] << 16) & in6->sin6_addr.u.Word[1])
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
 			in6->sin6_addr.__u6_addr.__u6_addr32[0]
 #else
 			in6->sin6_addr.s6_addr32[0]
