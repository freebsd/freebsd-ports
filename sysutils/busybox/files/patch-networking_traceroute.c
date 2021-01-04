--- networking/traceroute.c.orig	2021-01-01 13:30:02 UTC
+++ networking/traceroute.c
@@ -634,8 +634,8 @@ packet4_ok(int read_len, const struct sockaddr_in *fro
 // Off: since we do not form the entire IP packet,
 // but defer it to kernel, we can't set source port,
 // and thus can't check it here in the reply
-			/* && up->source == htons(ident) */
-			 && up->dest == htons(port + seq)
+			/* && up->uh_sport == htons(ident) */
+			 && up->uh_dport == htons(port + seq)
 			) {
 				return (type == ICMP_TIMXCEED ? -1 : code + 1);
 			}
@@ -932,8 +932,13 @@ common_traceroute_main(int op, char **argv)
 		setsockopt_SOL_SOCKET_1(rcvsock, SO_DONTROUTE);
 
 #if ENABLE_TRACEROUTE6
+#ifdef __FreeBSD__
+#define SOL_V6_OPTION SOL_IPV6
+#else
+#define SOL_V6_OPTION SOL_RAW
+#endif
 	if (af == AF_INET6) {
-		if (setsockopt_int(rcvsock, SOL_RAW, IPV6_CHECKSUM, 2) != 0)
+		if (setsockopt_int(rcvsock, SOL_V6_OPTION, IPV6_CHECKSUM, 2) != 0)
 			bb_perror_msg_and_die("setsockopt(%s)", "IPV6_CHECKSUM");
 		xmove_fd(xsocket(af, SOCK_DGRAM, 0), sndsock);
 	} else
