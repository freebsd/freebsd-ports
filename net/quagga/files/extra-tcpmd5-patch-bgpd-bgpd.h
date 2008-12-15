--- bgpd/bgpd.h.orig	Wed Jan 11 03:10:10 2006
+++ bgpd/bgpd.h	Mon Jan 30 08:52:06 2006
@@ -347,6 +347,9 @@
 #define PEER_FLAG_DYNAMIC_CAPABILITY        (1 << 5) /* dynamic capability */
 #define PEER_FLAG_DISABLE_CONNECTED_CHECK   (1 << 6) /* disable-connected-check */
 #define PEER_FLAG_LOCAL_AS_NO_PREPEND       (1 << 7) /* local-as no-prepend */
+#ifdef QUAGGA_TCP_MD5SIG
+#define PEER_FLAG_TCP_SIGNATURE             (1 << 9) /* use TCP-MD5 digest */
+#endif /* QUAGGA_TCP_MD5SIG */
 
   /* NSF mode (graceful restart) */
   u_char nsf[AFI_MAX][SAFI_MAX];
