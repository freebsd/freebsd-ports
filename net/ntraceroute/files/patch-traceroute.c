--- traceroute.c.orig	2016-09-02 21:07:07 UTC
+++ traceroute.c
@@ -2,6 +2,11 @@
 /*
  *  STILL BROKEN: traceroute -g on linux (LSRR)
  */
+#include <string.h>
+#if __FreeBSD_version >= 1100030
+#define	BYTESWAP_IP_FLAGS
+#define	BYTESWAP_IP_LEN
+#endif
 #define TRACE_TOS 1
 #define SPRAY
 #define FIXT
@@ -798,7 +803,7 @@ struct opacket {
               struct icmp icmp_probe;
         } ip_payload;
 #endif /* V6.3.0 */
-};
+} __attribute__((packed));
 
 #ifdef SPRAY
 /*
