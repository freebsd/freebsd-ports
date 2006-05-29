--- lib/sockopt.h.orig	Wed May  4 01:13:05 2005
+++ lib/sockopt.h	Thu May 11 10:08:05 2006
@@ -40,6 +40,10 @@
  */
 #define SOPT_SIZE_CMSG_PKTINFO_IPV6() (sizeof (struct in6_pktinfo));
 
+#ifdef QUAGGA_TCP_MD5SIG
+extern int sockopt_tcp_signature(int family, int sock, int enable);
+#endif /* QUAGGA_TCP_MD5SIG */
+
 /*
  * Size defines for control messages used to get ifindex.  We define
  * values for each method, and define a macro that can be used by code
