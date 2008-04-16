--- trickle-overload.c.orig	2004-12-13 02:21:53.000000000 +0100
+++ trickle-overload.c	2008-04-15 21:44:29.000000000 +0200
@@ -141,8 +141,12 @@
 DECLARE(dup2, int, (int, int));
 
 #ifdef HAVE_SENDFILE
+#ifdef __FreeBSD__
+DECLARE(sendfile, ssize_t, (int, int, off_t, size_t, struct sf_hdtr *, off_t *, int));
+#else
 DECLARE(sendfile, ssize_t, (int, int, off_t *, size_t));
 #endif
+#endif
 
 static int             delay(int, ssize_t *, short);
 static struct timeval *getdelay(struct sockdesc *, ssize_t *, short);
@@ -202,15 +206,11 @@
 
 	GETADDR(read);
 	GETADDR(readv);
-#ifndef __FreeBSD__
 	GETADDR(recv);
-#endif /* !__FreeBSD__ */
 	GETADDR(recvfrom);
 
 	GETADDR(writev);
-#ifndef __FreeBSD__
 	GETADDR(send);
-#endif /* !__FreeBSD__ */
 	GETADDR(sendto);
 
 	GETADDR(select);
@@ -701,7 +701,6 @@
 	return (ret);
 }
 
-#ifndef __FreeBSD__ 
 ssize_t
 recv(int sock, void *buf, size_t len, int flags)
 {
@@ -730,7 +729,6 @@
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 #ifdef __sun__
 ssize_t
@@ -832,7 +830,6 @@
 	return (ret);
 }
 
-#ifndef __FreeBSD__
 ssize_t
 send(int sock, const void *buf, size_t len, int flags)
 {
@@ -862,7 +859,6 @@
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 ssize_t
 sendto(int sock, const void *buf, size_t len, int flags, const struct sockaddr *to,
@@ -1005,7 +1001,11 @@
 
 #ifdef HAVE_SENDFILE
 ssize_t
+#ifdef __FreeBSD__
+sendfile(int out_fd, int in_fd, off_t offset, size_t count, struct sf_hdtr *hdtr, off_t *sbytes, int flags)
+#else
 sendfile(int out_fd, int in_fd, off_t *offset, size_t count)
+#endif
 {
 	size_t inbytes = count, outbytes = count, bytes;
 	ssize_t ret = 0;
@@ -1021,8 +1021,11 @@
 	/* This is a slightly ugly hack. */
 	bytes = MIN(inbytes, outbytes);
 	if (bytes > 0)
+#ifdef __FreeBSD__
+		ret = (*libc_sendfile)(out_fd, in_fd, offset, bytes, hdtr, sbytes, flags);
+#else
 		ret = (*libc_sendfile)(out_fd, in_fd, offset, bytes);
-
+#endif
 	return (ret);
 }
 #endif	/* HAVE_SENDFILE */
