--- src/tuntap_bsd.c.orig	2015-12-28 11:20:16 UTC
+++ src/tuntap_bsd.c
@@ -21,7 +21,7 @@ mlvpn_tuntap_read(struct tuntap_s *tunta
     mlvpn_tunnel_t *rtun = NULL;
     mlvpn_pkt_t *pkt;
     ssize_t ret;
-    u_char data[DEFAULT_MTU]
+    u_char data[DEFAULT_MTU];
     struct iovec iov[2];
     uint32_t type;
 
