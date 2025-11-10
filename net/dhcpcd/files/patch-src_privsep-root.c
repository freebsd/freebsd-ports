--- src/privsep-root.c.orig	2025-06-01 18:40:28 UTC
+++ src/privsep-root.c
@@ -210,6 +210,7 @@ ps_root_writeerror(struct dhcpcd_ctx *ctx, ssize_t res
 		{ .iov_base = &psr, .iov_len = sizeof(psr) },
 		{ .iov_base = data, .iov_len = len },
 	};
+	struct msghdr msg = { .msg_iov = iov, .msg_iovlen = __arraycount(iov) };
 	ssize_t err;
 	int fd = PS_ROOT_FD(ctx);
 
@@ -217,7 +218,7 @@ ps_root_writeerror(struct dhcpcd_ctx *ctx, ssize_t res
 	logdebugx("%s: result %zd errno %d", __func__, result, errno);
 #endif
 
-	err = writev(fd, iov, __arraycount(iov));
+	err = sendmsg(fd, &msg, MSG_EOR);
 
 	/* Error sending the message? Try sending the error of sending. */
 	if (err == -1) {
@@ -227,7 +228,7 @@ ps_root_writeerror(struct dhcpcd_ctx *ctx, ssize_t res
 		psr.psr_errno = errno;
 		iov[1].iov_base = NULL;
 		iov[1].iov_len = 0;
-		err = writev(fd, iov, __arraycount(iov));
+		err = sendmsg(fd, &msg, MSG_EOR);
 	}
 
 	return err;
