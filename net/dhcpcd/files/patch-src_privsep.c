--- src/privsep.c.orig	2025-06-01 18:40:28 UTC
+++ src/privsep.c
@@ -934,7 +934,9 @@ ps_sendpsmmsg(struct dhcpcd_ctx *ctx, int fd,
 	} else
 		iovlen = 1;
 
-	len = writev(fd, iov, iovlen);
+	len = sendmsg(fd,
+	    &(struct msghdr){ .msg_iov = iov, .msg_iovlen = iovlen }, MSG_EOR);
+
 	if (len == -1) {
 		if (ctx->options & DHCPCD_FORKED &&
 		    !(ctx->options & DHCPCD_PRIVSEPROOT))
@@ -1063,7 +1065,9 @@ ps_sendcmdmsg(int fd, uint16_t cmd, const struct msghd
 	    psm.ps_namelen + psm.ps_controllen + psm.ps_datalen + cmsg_padlen;
 	if (psm.ps_datalen != 0)
 		memcpy(p, msg->msg_iov[0].iov_base, psm.ps_datalen);
-	return writev(fd, iov, __arraycount(iov));
+	return sendmsg(fd,
+	    &(struct msghdr){ .msg_iov = iov, .msg_iovlen = __arraycount(iov) },
+	    MSG_EOR);
 
 nobufs:
 	errno = ENOBUFS;
