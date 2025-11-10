--- src/privsep.c.orig	2025-06-01 18:40:28 UTC
+++ src/privsep.c
@@ -895,7 +895,7 @@ ps_sendpsmmsg(struct dhcpcd_ctx *ctx, int fd,
 		{ .iov_base = NULL, },	/* payload 2 */
 		{ .iov_base = NULL, },	/* payload 3 */
 	};
-	int iovlen;
+	struct msghdr m = { .msg_iov = iov, .msg_iovlen = 1 };
 	ssize_t len;
 
 	if (msg != NULL) {
@@ -909,6 +909,7 @@ ps_sendpsmmsg(struct dhcpcd_ctx *ctx, int fd,
 		iovp->iov_base = msg->msg_name;
 		iovp->iov_len = msg->msg_namelen;
 		iovp++;
+		m.msg_iovlen++;
 
 		cmsg_padlen =
 		    CALC_CMSG_PADLEN(msg->msg_controllen, msg->msg_namelen);
@@ -916,25 +917,26 @@ ps_sendpsmmsg(struct dhcpcd_ctx *ctx, int fd,
 		iovp->iov_len = cmsg_padlen;
 		iovp->iov_base = cmsg_padlen != 0 ? padding : NULL;
 		iovp++;
+		m.msg_iovlen++;
 
 		iovp->iov_base = msg->msg_control;
 		iovp->iov_len = msg->msg_controllen;
-		iovlen = 4;
+		iovp++;
+		m.msg_iovlen++;
 
 		for (i = 0; i < (int)msg->msg_iovlen; i++) {
-			if ((size_t)(iovlen + i) > __arraycount(iov)) {
+			if ((size_t)(m.msg_iovlen++) > __arraycount(iov)) {
 				errno =	ENOBUFS;
 				return -1;
 			}
-			iovp++;
 			iovp->iov_base = msg->msg_iov[i].iov_base;
 			iovp->iov_len = msg->msg_iov[i].iov_len;
+			iovp++;
 		}
-		iovlen += i;
-	} else
-		iovlen = 1;
+	}
 
-	len = writev(fd, iov, iovlen);
+	len = sendmsg(fd, &m, MSG_EOR);
+
 	if (len == -1) {
 		if (ctx->options & DHCPCD_FORKED &&
 		    !(ctx->options & DHCPCD_PRIVSEPROOT))
@@ -1028,6 +1030,7 @@ ps_sendcmdmsg(int fd, uint16_t cmd, const struct msghd
 		{ .iov_base = &psm, .iov_len = sizeof(psm) },
 		{ .iov_base = data, .iov_len = 0 },
 	};
+	struct msghdr m = { .msg_iov = iov, .msg_iovlen = __arraycount(iov) };
 	size_t dl = sizeof(data);
 	socklen_t cmsg_padlen =
 	    CALC_CMSG_PADLEN(msg->msg_controllen, msg->msg_namelen);
@@ -1063,8 +1066,9 @@ ps_sendcmdmsg(int fd, uint16_t cmd, const struct msghd
 	    psm.ps_namelen + psm.ps_controllen + psm.ps_datalen + cmsg_padlen;
 	if (psm.ps_datalen != 0)
 		memcpy(p, msg->msg_iov[0].iov_base, psm.ps_datalen);
-	return writev(fd, iov, __arraycount(iov));
 
+	return sendmsg(fd, &m, MSG_EOR);
+
 nobufs:
 	errno = ENOBUFS;
 	return -1;
@@ -1089,7 +1093,7 @@ ps_recvmsg(int rfd, unsigned short events, uint16_t cm
 	if (!(events & ELE_READ))
 		logerrx("%s: unexpected event 0x%04x", __func__, events);
 
-	len = recvmsg(rfd, &msg, 0);
+	len = recvmsg(rfd, &msg, MSG_WAITALL);
 	if (len == -1) {
 		logerr("%s: recvmsg", __func__);
 		return len;
