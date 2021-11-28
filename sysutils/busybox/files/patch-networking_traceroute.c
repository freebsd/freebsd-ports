--- networking/traceroute.c.orig	2021-08-15 18:44:35 UTC
+++ networking/traceroute.c
@@ -963,8 +963,12 @@ traceroute_init(int op, char **argv)
 	if (af == AF_INET) {
 		xmove_fd(xsocket(AF_INET, SOCK_RAW, IPPROTO_ICMP), rcvsock);
 #if ENABLE_FEATURE_TRACEROUTE_VERBOSE
+#if defined(IP_PKTINFO)
 		/* want recvmsg to report target local address (for -v) */
 		setsockopt_1(rcvsock, IPPROTO_IP, IP_PKTINFO);
+#elif defined(IP_RECVDSTADDR)
+		setsockopt_1(rcvsock, IPPROTO_IP, IP_RECVDSTADDR);
+#endif
 #endif
 	}
 #if ENABLE_TRACEROUTE6
