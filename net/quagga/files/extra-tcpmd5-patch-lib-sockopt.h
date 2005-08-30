--- lib/sockopt.h.orig	Mon Nov 15 10:51:15 2004
+++ lib/sockopt.h	Fri Jan 28 17:52:57 2005
@@ -40,6 +40,9 @@
  */
 #define SOPT_SIZE_CMSG_PKTINFO_IPV6() (sizeof (struct in6_pktinfo));
 
+#ifdef QUAGGA_TCP_MD5SIG
+int sockopt_tcp_signature(int family, int sock, int enable);
+#endif /* QUAGGA_TCP_MD5SIG */
 /*
  * Size defines for control messages used to get ifindex.  We define
  * values for each method, and define a macro that can be used by code
