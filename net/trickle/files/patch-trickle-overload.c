--- trickle-overload.c.orig	2004-12-13 01:21:53 UTC
+++ trickle-overload.c
@@ -61,6 +61,7 @@
 
 #define SD_INSELECT 0x01
 
+
 struct sockdesc {
 	int                    sock;
 	int                    flags;
@@ -141,8 +142,12 @@ DECLARE(dup, int, (int));
 DECLARE(dup2, int, (int, int));
 
 #ifdef HAVE_SENDFILE
+#ifdef __FreeBSD__
+DECLARE(sendfile, int, (int, int, off_t, size_t, struct sf_hdtr *, off_t *, int));
+#else
 DECLARE(sendfile, ssize_t, (int, int, off_t *, size_t));
 #endif
+#endif
 
 static int             delay(int, ssize_t *, short);
 static struct timeval *getdelay(struct sockdesc *, ssize_t *, short);
@@ -202,15 +207,11 @@ trickle_init(void)
 
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
@@ -701,7 +702,6 @@ readv(int fd, const struct iovec *iov, i
 	return (ret);
 }
 
-#ifndef __FreeBSD__ 
 ssize_t
 recv(int sock, void *buf, size_t len, int flags)
 {
@@ -730,7 +730,6 @@ recv(int sock, void *buf, size_t len, in
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 #ifdef __sun__
 ssize_t
@@ -832,7 +831,6 @@ writev(int fd, const struct iovec *iov, 
 	return (ret);
 }
 
-#ifndef __FreeBSD__
 ssize_t
 send(int sock, const void *buf, size_t len, int flags)
 {
@@ -862,7 +860,6 @@ send(int sock, const void *buf, size_t l
 
 	return (ret);
 }
-#endif /* !__FreeBSD__ */
 
 ssize_t
 sendto(int sock, const void *buf, size_t len, int flags, const struct sockaddr *to,
@@ -1004,11 +1001,20 @@ accept(int sock, struct sockaddr *addr, 
 }
 
 #ifdef HAVE_SENDFILE
+#ifdef __FreeBSD__
+int
+sendfile(int out_fd, int in_fd, off_t offset, size_t count, struct sf_hdtr *hdtr, off_t *sbytes, int flags)
+#else
 ssize_t
 sendfile(int out_fd, int in_fd, off_t *offset, size_t count)
+#endif
 {
 	size_t inbytes = count, outbytes = count, bytes;
+#ifdef __FreeBSD__
+	int ret = 0;
+#else
 	ssize_t ret = 0;
+#endif
 
 	INIT;
 
@@ -1021,8 +1027,11 @@ sendfile(int out_fd, int in_fd, off_t *o
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
