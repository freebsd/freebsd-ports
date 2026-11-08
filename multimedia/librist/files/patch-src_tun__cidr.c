--- src/tun_cidr.c.orig	2026-07-30 03:39:06 UTC
+++ src/tun_cidr.c
@@ -15,6 +15,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/socket.h> // for AF_INET and AF_INET6
+#include <netinet/in.h> // for in6_addr
+
+
 int rist_tun_parse_cidr(const char *cidr, char *ip_out, size_t ip_len, int *prefix_out)
 {
 	const char *slash;
