--- src/core/ip_addr.h.orig	2018-03-01 16:24:06 UTC
+++ src/core/ip_addr.h
@@ -49,6 +49,10 @@ enum sip_protos { PROTO_NONE, PROTO_UDP,
 enum comp_methods { COMP_NONE, COMP_SIGCOMP, COMP_SERGZ };
 #endif
 
+#ifndef INADDR_LOOPBACK
+#define INADDR_LOOPBACK         (u_int32_t)0x7f000001
+#endif
+
 typedef struct ip_addr {
 	unsigned int af;	/* address family: AF_INET6 or AF_INET */
 	unsigned int len;	/* address len, 16 or 4 */
