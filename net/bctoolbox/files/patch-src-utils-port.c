--- src/utils/port.c.orig	2016-08-11 09:23:51 UTC
+++ src/utils/port.c
@@ -1238,7 +1238,7 @@ void bctbx_sockaddr_remove_nat64_mapping
 #ifdef _MSC_VER
 		if ((((in6->sin6_addr.u.Word[0] << 16) & in6->sin6_addr.u.Word[1]) == htonl(0x0064))
 			&& (((in6->sin6_addr.u.Word[2] << 16) & in6->sin6_addr.u.Word[3]) == htonl(0xff9b))) {
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
 		if ((in6->sin6_addr.__u6_addr.__u6_addr32[0] == htonl(0x0064)) && (in6->sin6_addr.__u6_addr.__u6_addr32[1] == htonl(0xff9b))) {
 #else
 		if ((in6->sin6_addr.s6_addr32[0] == htonl(0x0064)) && (in6->sin6_addr.s6_addr32[1] == htonl(0xff9b))) {
