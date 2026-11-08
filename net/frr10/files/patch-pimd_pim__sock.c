Ask for IP_HDRINCL on the register socket: only Linux implies it.

pim_msg_send() builds the outer IP header for every message it puts on
pim->reg_sock, which pim_reg_sock() creates with SOCK_RAW/IPPROTO_RAW.  Linux
implies IP_HDRINCL for IPPROTO_RAW, so that header is what goes on the wire.
BSD does not: rip_output() prepends a header of its own with ip_p taken from the
socket's protocol, so every PIM Register left FreeBSD as IP protocol 255 with
pimd's own header as payload, and the RP answered with an ICMP "protocol 255
unreachable" rather than learning the source.

Submitted upstream: https://github.com/FRRouting/frr/pull/23455

--- pimd/pim_sock.c.orig	2026-09-24 18:59:47 UTC
+++ pimd/pim_sock.c	2026-09-24 18:59:47 UTC
@@ -198,6 +198,26 @@ int pim_reg_sock(void)
 		return PIM_SOCK_ERR_SOCKET;
 	}
 
+#if PIM_IPV == 4
+	/*
+	 * pim_msg_send() builds the outer IP header itself for everything it
+	 * puts on this socket.  Linux implies IP_HDRINCL for an IPPROTO_RAW
+	 * socket, so that header goes on the wire as written; BSD does not,
+	 * and without the option the kernel prepends a second header of its
+	 * own carrying ip_p = IPPROTO_RAW.  A Register then leaves as IP
+	 * protocol 255 with FRR's header as payload, and the RP answers
+	 * "protocol 255 unreachable" instead of learning the source.
+	 * Setting it explicitly is a no-op on Linux and the fix on BSD.
+	 */
+	{
+		int hincl = 1;
+
+		if (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)))
+			zlog_warn("Could not set IP_HDRINCL on socket fd=%d: errno=%d: %s", fd,
+				  errno, safe_strerror(errno));
+	}
+#endif
+
 	if (sockopt_reuseaddr(fd)) {
 		close(fd);
 		return PIM_SOCK_ERR_REUSE;
