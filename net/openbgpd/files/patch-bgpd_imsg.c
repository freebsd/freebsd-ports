Index: bgpd/imsg.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/imsg.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/imsg.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/imsg.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: imsg.c,v 1.42 2008/03/24 16:11:02 deraadt Exp $ */
+/*	$OpenBSD: imsg.c,v 1.47 2009/06/08 08:30:06 dlg Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -16,7 +16,9 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/socket.h>
 #include <sys/uio.h>
 
 #include <errno.h>
@@ -24,7 +26,9 @@
 #include <string.h>
 #include <unistd.h>
 
-#include "bgpd.h"
+#include "imsg.h"
+
+int	 imsg_get_fd(struct imsgbuf *);
 
 void
 imsg_init(struct imsgbuf *ibuf, int fd)
@@ -37,14 +41,14 @@ imsg_init(struct imsgbuf *ibuf, int fd)
 	TAILQ_INIT(&ibuf->fds);
 }
 
-int
+ssize_t
 imsg_read(struct imsgbuf *ibuf)
 {
 	struct msghdr		 msg;
 	struct cmsghdr		*cmsg;
 	union {
 		struct cmsghdr hdr;
-		char buf[CMSG_SPACE(sizeof(int) * 16)];
+		char	buf[CMSG_SPACE(sizeof(int) * 16)];
 	} cmsgbuf;
 	struct iovec		 iov;
 	ssize_t			 n;
@@ -52,6 +56,7 @@ imsg_read(struct imsgbuf *ibuf)
 	struct imsg_fd		*ifd;
 
 	bzero(&msg, sizeof(msg));
+
 	iov.iov_base = ibuf->r.buf + ibuf->r.wpos;
 	iov.iov_len = sizeof(ibuf->r.buf) - ibuf->r.wpos;
 	msg.msg_iov = &iov;
@@ -61,7 +66,6 @@ imsg_read(struct imsgbuf *ibuf)
 
 	if ((n = recvmsg(ibuf->fd, &msg, 0)) == -1) {
 		if (errno != EINTR && errno != EAGAIN) {
-			log_warn("imsg_read: pipe read error");
 			return (-1);
 		}
 		return (-2);
@@ -74,19 +78,20 @@ imsg_read(struct imsgbuf *ibuf)
 		if (cmsg->cmsg_level == SOL_SOCKET &&
 		    cmsg->cmsg_type == SCM_RIGHTS) {
 			fd = (*(int *)CMSG_DATA(cmsg));
-			if ((ifd = calloc(1, sizeof(struct imsg_fd))) == NULL)
-				fatal("imsg_read calloc");
+			if ((ifd = calloc(1, sizeof(struct imsg_fd))) == NULL) {
+				/* XXX: this return can leak */
+				return (-1);
+			}
 			ifd->fd = fd;
 			TAILQ_INSERT_TAIL(&ibuf->fds, ifd, entry);
-		} else
-			log_warn("imsg_read: got unexpected ctl data level %d "
-			    "type %d", cmsg->cmsg_level, cmsg->cmsg_type);
+		}
+		/* we do not handle other ctl data level */
 	}
 
 	return (n);
 }
 
-int
+ssize_t
 imsg_get(struct imsgbuf *ibuf, struct imsg *imsg)
 {
 	size_t			 av, left, datalen;
@@ -99,18 +104,21 @@ imsg_get(struct imsgbuf *ibuf, struct im
 	memcpy(&imsg->hdr, ibuf->r.buf, sizeof(imsg->hdr));
 	if (imsg->hdr.len < IMSG_HEADER_SIZE ||
 	    imsg->hdr.len > MAX_IMSGSIZE) {
-		log_warnx("imsg_get: imsg hdr len %u out of bounds, type=%u",
-		    imsg->hdr.len, imsg->hdr.type);
+		errno = ERANGE;
 		return (-1);
 	}
 	if (imsg->hdr.len > av)
 		return (0);
 	datalen = imsg->hdr.len - IMSG_HEADER_SIZE;
 	ibuf->r.rptr = ibuf->r.buf + IMSG_HEADER_SIZE;
-	if ((imsg->data = malloc(datalen)) == NULL) {
-		log_warn("imsg_get");
+	if ((imsg->data = malloc(datalen)) == NULL)
 		return (-1);
-	}
+
+	if (imsg->hdr.flags & IMSGF_HASFD)
+		imsg->fd = imsg_get_fd(ibuf);
+	else
+		imsg->fd = -1;
+
 	memcpy(imsg->data, ibuf->r.rptr, datalen);
 
 	if (imsg->hdr.len < av) {
@@ -124,11 +132,10 @@ imsg_get(struct imsgbuf *ibuf, struct im
 }
 
 int
-imsg_compose(struct imsgbuf *ibuf, enum imsg_type type, u_int32_t peerid,
-    pid_t pid, int fd, const void *data, u_int16_t datalen)
+imsg_compose(struct imsgbuf *ibuf, u_int32_t type, u_int32_t peerid,
+    pid_t pid, int fd, void *data, u_int16_t datalen)
 {
 	struct buf	*wbuf;
-	int		 n;
 
 	if ((wbuf = imsg_create(ibuf, type, peerid, pid, datalen)) == NULL)
 		return (-1);
@@ -138,33 +145,55 @@ imsg_compose(struct imsgbuf *ibuf, enum 
 
 	wbuf->fd = fd;
 
-	if ((n = imsg_close(ibuf, wbuf)) < 0)
+	imsg_close(ibuf, wbuf);
+
+	return (1);
+}
+
+int
+imsg_composev(struct imsgbuf *ibuf, u_int32_t type, u_int32_t peerid,
+    pid_t pid, int fd, const struct iovec *iov, int iovcnt)
+{
+	struct buf	*wbuf;
+	int		 i, datalen = 0;
+
+	for (i = 0; i < iovcnt; i++)
+		datalen += iov[i].iov_len;
+
+	if ((wbuf = imsg_create(ibuf, type, peerid, pid, datalen)) == NULL)
 		return (-1);
 
-	return (n);
+	for (i = 0; i < iovcnt; i++)
+		if (imsg_add(wbuf, iov[i].iov_base, iov[i].iov_len) == -1)
+			return (-1);
+
+	wbuf->fd = fd;
+
+	imsg_close(ibuf, wbuf);
+
+	return (1);
 }
 
+/* ARGSUSED */
 struct buf *
-imsg_create(struct imsgbuf *ibuf, enum imsg_type type, u_int32_t peerid,
+imsg_create(struct imsgbuf *ibuf, u_int32_t type, u_int32_t peerid,
     pid_t pid, u_int16_t datalen)
 {
 	struct buf	*wbuf;
 	struct imsg_hdr	 hdr;
 
-	if (datalen > MAX_IMSGSIZE - IMSG_HEADER_SIZE) {
-		log_warnx("imsg_create: len %u > MAX_IMSGSIZE; "
-		    "type %u peerid %lu", datalen + IMSG_HEADER_SIZE,
-		    type, peerid);
+	datalen += IMSG_HEADER_SIZE;
+	if (datalen > MAX_IMSGSIZE) {
+		errno = ERANGE;
 		return (NULL);
 	}
 
-	hdr.len = datalen + IMSG_HEADER_SIZE;
 	hdr.type = type;
+	hdr.flags = 0;
 	hdr.peerid = peerid;
 	if ((hdr.pid = pid) == 0)
 		hdr.pid = ibuf->pid;
-	if ((wbuf = buf_open(hdr.len)) == NULL) {
-		log_warn("imsg_create: buf_open");
+	if ((wbuf = buf_dynamic(datalen, MAX_IMSGSIZE)) == NULL) {
 		return (NULL);
 	}
 	if (imsg_add(wbuf, &hdr, sizeof(hdr)) == -1)
@@ -174,28 +203,30 @@ imsg_create(struct imsgbuf *ibuf, enum i
 }
 
 int
-imsg_add(struct buf *msg, const void *data, u_int16_t datalen)
+imsg_add(struct buf *msg, void *data, u_int16_t datalen)
 {
 	if (datalen)
 		if (buf_add(msg, data, datalen) == -1) {
-			log_warnx("imsg_add: buf_add error");
 			buf_free(msg);
 			return (-1);
 		}
 	return (datalen);
 }
 
-int
+void
 imsg_close(struct imsgbuf *ibuf, struct buf *msg)
 {
-	int	n;
+	struct imsg_hdr	*hdr;
 
-	if ((n = buf_close(&ibuf->w, msg)) < 0) {
-			log_warnx("imsg_close: buf_close error");
-			buf_free(msg);
-			return (-1);
-	}
-	return (n);
+	hdr = (struct imsg_hdr *)msg->buf;
+
+	hdr->flags &= ~IMSGF_HASFD;
+	if (msg->fd != -1)
+		hdr->flags |= IMSGF_HASFD;
+
+	hdr->len = (u_int16_t)msg->wpos;
+
+	buf_close(&ibuf->w, msg);
 }
 
 void
@@ -219,3 +250,19 @@ imsg_get_fd(struct imsgbuf *ibuf)
 
 	return (fd);
 }
+
+int
+imsg_flush(struct imsgbuf *ibuf)
+{
+	while (ibuf->w.queued)
+		if (msgbuf_write(&ibuf->w) < 0)
+			return (-1);
+	return (0);
+}
+
+void
+imsg_clear(struct imsgbuf *ibuf)
+{
+	while (ibuf->w.queued)
+		msgbuf_clear(&ibuf->w);
+}
