--- lib/ngtcp2_addr.c.orig	2020-07-27 10:35:08 UTC
+++ lib/ngtcp2_addr.c
@@ -26,6 +26,10 @@
 
 #include <string.h>
 #include <assert.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <netinet/in.h>
+#endif
 #include <netinet/ip.h>
 
 ngtcp2_addr *ngtcp2_addr_init(ngtcp2_addr *dest, const struct sockaddr *addr,
