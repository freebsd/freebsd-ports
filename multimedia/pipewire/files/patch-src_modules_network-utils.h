--- src/modules/network-utils.h.orig	2024-07-22 08:00:23 UTC
+++ src/modules/network-utils.h
@@ -8,6 +8,10 @@
 #include <net/if.h>
 #include <errno.h>
 
+#ifdef __FreeBSD__
+#define ifr_ifindex ifr_index
+#endif
+
 static inline int pw_net_parse_address(const char *address, uint16_t port,
 		struct sockaddr_storage *addr, socklen_t *len)
 {
