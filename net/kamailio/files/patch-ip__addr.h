--- ip_addr.h.orig	2015-09-05 21:17:34 UTC
+++ ip_addr.h
@@ -53,6 +53,10 @@ enum comp_methods { COMP_NONE, COMP_SIGC
 #define INADDR_LOOPBACK         (u_int32_t)0x7f000001
 #endif
 
+#ifndef INADDR_LOOPBACK
+#define INADDR_LOOPBACK         (u_int32_t)0x7f000001
+#endif
+
 struct ip_addr{
 	unsigned int af; /* address family: AF_INET6 or AF_INET */
 	unsigned int len;    /* address len, 16 or 4 */
