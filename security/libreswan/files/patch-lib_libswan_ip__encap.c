--- lib/libswan/ip_encap.c.orig	2021-05-21 18:52:58 UTC
+++ lib/libswan/ip_encap.c
@@ -19,6 +19,7 @@
 #ifdef linux
 #  include <linux/udp.h>		/* for TCP_ENCAP_ESPINTCP and UDP_ENCAP_ESPINUDP */
 #else
+#  include <sys/types.h>
 #  include <netinet/udp.h>		/* for UDP_ENCAP_ESPINUDP aka NAT */
 #endif
 
