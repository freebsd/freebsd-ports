--- src/tun.c.orig	2018-04-14 07:52:35 UTC
+++ src/tun.c
@@ -895,3 +895,22 @@ ssize_t tun_read(int sockfd, void *buf, size_t len)
 	return read(sockfd, buf, len);
 }
 #endif
+
+#ifndef __FreeBSD__
+int tun_claim(int sockfd)
+{
+
+	return (0);
+}
+#else
+/*
+ * FreeBSD has a mechanism by which a tunnel has a single controlling process,
+ * and only that one process may close it.  When the controlling process closes
+ * the tunnel, the state is torn down.
+ */
+int tun_claim(int sockfd)
+{
+
+	return (ioctl(sockfd, TUNSIFPID, 0));
+}
+#endif	/* !__FreeBSD__ */
