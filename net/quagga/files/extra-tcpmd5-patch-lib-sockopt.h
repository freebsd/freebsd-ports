--- lib/sockopt.h.orig	2008-09-05 18:27:26.000000000 +0400
+++ lib/sockopt.h	2008-12-15 19:36:45.000000000 +0300
@@ -44,6 +44,10 @@
  */
 #define SOPT_SIZE_CMSG_PKTINFO_IPV6() (sizeof (struct in6_pktinfo));
 
+#ifdef QUAGGA_TCP_MD5SIG
+extern int sockopt_tcp_signature(int family, int sock, int enable);
+#endif /* QUAGGA_TCP_MD5SIG */
+
 /*
  * Size defines for control messages used to get ifindex.  We define
  * values for each method, and define a macro that can be used by code
@@ -101,6 +105,4 @@
 extern void sockopt_iphdrincl_swab_htosys (struct ip *iph);
 extern void sockopt_iphdrincl_swab_systoh (struct ip *iph);
 
-extern int sockopt_tcp_signature(int sock, union sockunion *su,
-                                 const char *password);
 #endif /*_ZEBRA_SOCKOPT_H */
