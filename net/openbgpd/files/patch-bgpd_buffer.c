Index: bgpd/buffer.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/buffer.c,v
retrieving revision 1.1.1.1
retrieving revision 1.1.1.2
diff -u -p -r1.1.1.1 -r1.1.1.2
--- bgpd/buffer.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/buffer.c	9 Jul 2009 16:49:54 -0000	1.1.1.2
@@ -1,4 +1,4 @@
-/*	$OpenBSD: buffer.c,v 1.39 2008/03/24 16:11:02 deraadt Exp $ */
+/*	$OpenBSD: buffer.c,v 1.43 2009/06/06 06:33:15 eric Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -16,18 +16,19 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/queue.h>
+#include <sys/socket.h>
 #include <sys/uio.h>
 
 #include <errno.h>
-#include <limits.h>
-#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
-#include "bgpd.h"
+#include "imsg.h"
 
+int	buf_realloc(struct buf *, size_t);
 void	buf_enqueue(struct msgbuf *, struct buf *);
 void	buf_dequeue(struct msgbuf *, struct buf *);
 
@@ -42,35 +43,55 @@ buf_open(size_t len)
 		free(buf);
 		return (NULL);
 	}
-	buf->size = len;
+	buf->size = buf->max = len;
 	buf->fd = -1;
 
 	return (buf);
 }
 
 struct buf *
-buf_grow(struct buf *buf, size_t len)
+buf_dynamic(size_t len, size_t max)
 {
-	void	*p;
+	struct buf	*buf;
 
-	if ((p = realloc(buf->buf, buf->size + len)) == NULL) {
-		free(buf->buf);
-		buf->buf = NULL;
-		buf->size = 0;
+	if (max < len)
+		return (NULL);
+
+	if ((buf = buf_open(len)) == NULL)
 		return (NULL);
-	}
 
-	buf->buf = p;
-	buf->size += len;
+	if (max > 0)
+		buf->max = max;
 
 	return (buf);
 }
 
 int
+buf_realloc(struct buf *buf, size_t len)
+{
+	u_char	*b;
+
+	/* on static buffers max is eq size and so the following fails */
+	if (buf->wpos + len > buf->max) {
+		errno = ENOMEM;
+		return (-1);
+	}
+
+	b = realloc(buf->buf, buf->wpos + len);
+	if (b == NULL)
+		return (-1);
+	buf->buf = b;
+	buf->size = buf->wpos + len;
+
+	return (0);
+}
+
+int
 buf_add(struct buf *buf, const void *data, size_t len)
 {
 	if (buf->wpos + len > buf->size)
-		return (-1);
+		if (buf_realloc(buf, len) == -1)
+			return (-1);
 
 	memcpy(buf->buf + buf->wpos, data, len);
 	buf->wpos += len;
@@ -83,27 +104,60 @@ buf_reserve(struct buf *buf, size_t len)
 	void	*b;
 
 	if (buf->wpos + len > buf->size)
-		return (NULL);
+		if (buf_realloc(buf, len) == -1)
+			return (NULL);
 
 	b = buf->buf + buf->wpos;
 	buf->wpos += len;
 	return (b);
 }
 
-int
+void *
+buf_seek(struct buf *buf, size_t pos, size_t len)
+{
+	/* only allowed to seek in already written parts */
+	if (pos + len > buf->wpos)
+		return (NULL);
+
+	return (buf->buf + pos);
+}
+
+size_t
+buf_size(struct buf *buf)
+{
+	return (buf->wpos);
+}
+
+size_t
+buf_left(struct buf *buf)
+{
+	return (buf->max - buf->wpos);
+}
+
+void
 buf_close(struct msgbuf *msgbuf, struct buf *buf)
 {
 	buf_enqueue(msgbuf, buf);
-	return (1);
 }
 
 int
-buf_write(int sock, struct buf *buf)
+buf_write(struct msgbuf *msgbuf)
 {
+	struct iovec	 iov[IOV_MAX];
+	struct buf	*buf, *next;
+	unsigned int	 i = 0;
 	ssize_t	n;
 
-	if ((n = write(sock, buf->buf + buf->rpos,
-	    buf->size - buf->rpos)) == -1) {
+	bzero(&iov, sizeof(iov));
+	TAILQ_FOREACH(buf, &msgbuf->bufs, entry) {
+		if (i >= IOV_MAX)
+			break;
+		iov[i].iov_base = buf->buf + buf->rpos;
+		iov[i].iov_len = buf->size - buf->rpos;
+		i++;
+	}
+
+	if ((n = writev(msgbuf->fd, iov, i)) == -1) {
 		if (errno == EAGAIN || errno == ENOBUFS ||
 		    errno == EINTR)	/* try later */
 			return (0);
@@ -116,11 +170,19 @@ buf_write(int sock, struct buf *buf)
 		return (-2);
 	}
 
-	if (buf->rpos + n < buf->size) {	/* not all data written yet */
-		buf->rpos += n;
-		return (0);
-	} else
-		return (1);
+	for (buf = TAILQ_FIRST(&msgbuf->bufs); buf != NULL && n > 0;
+	    buf = next) {
+		next = TAILQ_NEXT(buf, entry);
+		if (buf->rpos + n >= buf->size) {
+			n -= buf->size - buf->rpos;
+			buf_dequeue(msgbuf, buf);
+		} else {
+			buf->rpos += n;
+			n = 0;
+		}
+	}
+
+	return (0);
 }
 
 void
@@ -152,13 +214,13 @@ msgbuf_write(struct msgbuf *msgbuf)
 {
 	struct iovec	 iov[IOV_MAX];
 	struct buf	*buf, *next;
-	int		 i = 0;
+	unsigned int	 i = 0;
 	ssize_t		 n;
 	struct msghdr	 msg;
 	struct cmsghdr	*cmsg;
 	union {
-		struct cmsghdr hdr;
-		char	buf[CMSG_SPACE(sizeof(int))];
+		struct cmsghdr	hdr;
+		char		buf[CMSG_SPACE(sizeof(int))];
 	} cmsgbuf;
 
 	bzero(&iov, sizeof(iov));
@@ -167,7 +229,7 @@ msgbuf_write(struct msgbuf *msgbuf)
 		if (i >= IOV_MAX)
 			break;
 		iov[i].iov_base = buf->buf + buf->rpos;
-		iov[i].iov_len = buf->size - buf->rpos;
+		iov[i].iov_len = buf->wpos - buf->rpos;
 		i++;
 		if (buf->fd != -1)
 			break;
@@ -211,8 +273,8 @@ msgbuf_write(struct msgbuf *msgbuf)
 	for (buf = TAILQ_FIRST(&msgbuf->bufs); buf != NULL && n > 0;
 	    buf = next) {
 		next = TAILQ_NEXT(buf, entry);
-		if (buf->rpos + n >= buf->size) {
-			n -= buf->size - buf->rpos;
+		if (buf->rpos + n >= buf->wpos) {
+			n -= buf->wpos - buf->rpos;
 			buf_dequeue(msgbuf, buf);
 		} else {
 			buf->rpos += n;
