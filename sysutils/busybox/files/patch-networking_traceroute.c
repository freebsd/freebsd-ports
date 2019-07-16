--- networking/traceroute.c.orig	2018-12-30 15:14:20 UTC
+++ networking/traceroute.c
@@ -635,7 +635,7 @@ packet4_ok(int read_len, const struct so
 // but defer it to kernel, we can't set source port,
 // and thus can't check it here in the reply
 			/* && up->source == htons(ident) */
-			 && up->dest == htons(port + seq)
+			 && up->uh_dport == htons(port + seq)
 			) {
 				return (type == ICMP_TIMXCEED ? -1 : code + 1);
 			}
@@ -933,7 +933,7 @@ common_traceroute_main(int op, char **ar
 
 #if ENABLE_TRACEROUTE6
 	if (af == AF_INET6) {
-		if (setsockopt_int(rcvsock, SOL_RAW, IPV6_CHECKSUM, 2) != 0)
+		if (setsockopt_int(rcvsock, SOL_IPV6, IPV6_CHECKSUM, 2) != 0)
 			bb_perror_msg_and_die("setsockopt(%s)", "IPV6_CHECKSUM");
 		xmove_fd(xsocket(af, SOCK_DGRAM, 0), sndsock);
 	} else
