--- src/privsep-root.c.orig	2025-11-14 15:38:04 UTC
+++ src/privsep-root.c
@@ -86,6 +86,7 @@ ps_root_readerrorcb(struct psr_ctx *psr_ctx)
 		{ .iov_base = psr_error, .iov_len = sizeof(*psr_error) },
 		{ .iov_base = NULL, .iov_len = 0 },
 	};
+	struct msghdr msg = { .msg_iov = iov, .msg_iovlen = __arraycount(iov) };
 	ssize_t len;
 
 #define PSR_ERROR(e)				\
@@ -98,37 +99,58 @@ ps_root_readerrorcb(struct psr_ctx *psr_ctx)
 	if (eloop_waitfd(fd) == -1)
 		PSR_ERROR(errno);
 
-	len = recv(fd, psr_error, sizeof(*psr_error), MSG_PEEK);
+	/* We peek at the psr_error structure to tell us how much of a buffer
+	 * we need to read the whole packet. */
+	len = recvmsg(fd, &msg, MSG_PEEK | MSG_WAITALL);
 	if (len == -1)
 		PSR_ERROR(errno);
-	else if ((size_t)len < sizeof(*psr_error))
-		PSR_ERROR(EINVAL);
 
-	if (psr_error->psr_datalen > SSIZE_MAX)
-		PSR_ERROR(ENOBUFS);
+	/* After this point, we MUST do another recvmsg even on a failure
+	 * to remove the message after peeking. */
+	if ((size_t)len < sizeof(*psr_error))
+		goto recv;
+
 	if (psr_ctx->psr_usemdata &&
 	    psr_error->psr_datalen > psr_ctx->psr_mdatalen)
 	{
 		void *d = realloc(psr_ctx->psr_mdata, psr_error->psr_datalen);
-		if (d == NULL)
-			PSR_ERROR(errno);
-		psr_ctx->psr_mdata = d;
-		psr_ctx->psr_mdatalen = psr_error->psr_datalen;
+
+		/* If we failed to malloc then psr_mdatalen will be smaller
+		 * than psr_datalen.
+		 * The following recvmsg will get MSG_TRUNC so the malloc error
+		 * will be reported there but more importantly the
+		 * message will be correctly discarded from the queue. */
+		if (d != NULL) {
+			psr_ctx->psr_mdata = d;
+			psr_ctx->psr_mdatalen = psr_error->psr_datalen;
+		}
 	}
 	if (psr_error->psr_datalen != 0) {
-		if (psr_ctx->psr_usemdata)
+		if (psr_ctx->psr_usemdata) {
 			iov[1].iov_base = psr_ctx->psr_mdata;
-		else {
-			if (psr_error->psr_datalen > psr_ctx->psr_datalen)
-				PSR_ERROR(ENOBUFS);
+			/* psr_mdatalen could be smaller then psr_datalen
+			 * if the above malloc failed. */
+			iov[1].iov_len =
+			    MIN(psr_ctx->psr_mdatalen, psr_error->psr_datalen);
+		} else {
 			iov[1].iov_base = psr_ctx->psr_data;
+			/* This should never be the case */
+			iov[1].iov_len =
+			    MIN(psr_ctx->psr_datalen, psr_error->psr_datalen);
 		}
-		iov[1].iov_len = psr_error->psr_datalen;
 	}
 
-	len = readv(fd, iov, __arraycount(iov));
+recv:
+	/* fd is SOCK_SEQPACKET and we mark the boundary with MSG_EOR
+	 * so this can never stall if the receive buffers are bigger
+	 * than the actual message. */
+	len = recvmsg(fd, &msg, MSG_WAITALL);
 	if (len == -1)
 		PSR_ERROR(errno);
+	else if ((size_t)len < sizeof(*psr_error))
+		PSR_ERROR(EINVAL);
+	else if (msg.msg_flags & MSG_TRUNC)
+		PSR_ERROR(ENOBUFS);
 	else if ((size_t)len != sizeof(*psr_error) + psr_error->psr_datalen)
 		PSR_ERROR(EINVAL);
 	return len;
