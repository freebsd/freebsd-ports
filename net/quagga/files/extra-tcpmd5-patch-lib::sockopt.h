--- lib/sockopt.h.orig	Fri Dec 13 20:15:29 2002
+++ lib/sockopt.h	Mon Jan  5 08:25:17 2004
@@ -37,5 +37,8 @@
 			     unsigned int mcast_addr,
 			     unsigned int ifindex);
 
+#ifdef TCP_MD5SIG
+int sockopt_tcp_signature(int family, int sock, int enable);
+#endif /* TCP_MD5SIG */
 
 #endif /*_ZEBRA_SOCKOPT_H */
