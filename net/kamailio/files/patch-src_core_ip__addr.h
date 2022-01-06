--- src/core/ip_addr.h.orig	2021-05-05 13:55:35 UTC
+++ src/core/ip_addr.h
@@ -51,6 +51,10 @@ typedef enum sip_protos { PROTO_NONE, PROTO_UDP, PROTO
 typedef enum comp_methods { COMP_NONE, COMP_SIGCOMP, COMP_SERGZ } comp_methods_t;
 #endif
 
+#ifndef INADDR_LOOPBACK
+#define INADDR_LOOPBACK         (u_int32_t)0x7f000001
+#endif
+
 typedef struct ip_addr {
 	unsigned int af;	/* address family: AF_INET6 or AF_INET */
 	unsigned int len;	/* address len, 16 or 4 */
