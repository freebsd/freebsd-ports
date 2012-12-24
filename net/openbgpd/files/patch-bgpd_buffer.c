Index: bgpd/buffer.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/buffer.c,v
retrieving revision 1.1.1.7
retrieving revision 1.3
diff -u -p -r1.1.1.7 -r1.3
--- bgpd/buffer.c	14 Feb 2010 20:19:57 -0000	1.1.1.7
+++ bgpd/buffer.c	8 Dec 2012 20:17:59 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: buffer.c,v 1.43 2009/06/06 06:33:15 eric Exp $	*/
+/*	$OpenBSD: buffer.c,v 1.44 2009/07/23 18:58:42 eric Exp $	*/
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -144,7 +144,7 @@ int
 buf_write(struct msgbuf *msgbuf)
 {
 	struct iovec	 iov[IOV_MAX];
-	struct buf	*buf, *next;
+	struct buf	*buf;
 	unsigned int	 i = 0;
 	ssize_t	n;
 
@@ -153,7 +153,7 @@ buf_write(struct msgbuf *msgbuf)
 		if (i >= IOV_MAX)
 			break;
 		iov[i].iov_base = buf->buf + buf->rpos;
-		iov[i].iov_len = buf->size - buf->rpos;
+		iov[i].iov_len = buf->wpos - buf->rpos;
 		i++;
 	}
 
@@ -170,17 +170,7 @@ buf_write(struct msgbuf *msgbuf)
 		return (-2);
 	}
 
-	for (buf = TAILQ_FIRST(&msgbuf->bufs); buf != NULL && n > 0;
-	    buf = next) {
-		next = TAILQ_NEXT(buf, entry);
-		if (buf->rpos + n >= buf->size) {
-			n -= buf->size - buf->rpos;
-			buf_dequeue(msgbuf, buf);
-		} else {
-			buf->rpos += n;
-			n = 0;
-		}
-	}
+	msgbuf_drain(msgbuf, n);
 
 	return (0);
 }
@@ -201,6 +191,24 @@ msgbuf_init(struct msgbuf *msgbuf)
 }
 
 void
+msgbuf_drain(struct msgbuf *msgbuf, size_t n)
+{
+	struct buf	*buf, *next;
+
+	for (buf = TAILQ_FIRST(&msgbuf->bufs); buf != NULL && n > 0;
+	    buf = next) {
+		next = TAILQ_NEXT(buf, entry);
+		if (buf->rpos + n >= buf->wpos) {
+			n -= buf->wpos - buf->rpos;
+			buf_dequeue(msgbuf, buf);
+		} else {
+			buf->rpos += n;
+			n = 0;
+		}
+	}
+}
+
+void
 msgbuf_clear(struct msgbuf *msgbuf)
 {
 	struct buf	*buf;
@@ -213,7 +221,7 @@ int
 msgbuf_write(struct msgbuf *msgbuf)
 {
 	struct iovec	 iov[IOV_MAX];
-	struct buf	*buf, *next;
+	struct buf	*buf;
 	unsigned int	 i = 0;
 	ssize_t		 n;
 	struct msghdr	 msg;
@@ -270,17 +278,7 @@ msgbuf_write(struct msgbuf *msgbuf)
 		buf->fd = -1;
 	}
 
-	for (buf = TAILQ_FIRST(&msgbuf->bufs); buf != NULL && n > 0;
-	    buf = next) {
-		next = TAILQ_NEXT(buf, entry);
-		if (buf->rpos + n >= buf->wpos) {
-			n -= buf->wpos - buf->rpos;
-			buf_dequeue(msgbuf, buf);
-		} else {
-			buf->rpos += n;
-			n = 0;
-		}
-	}
+	msgbuf_drain(msgbuf, n);
 
 	return (0);
 }
