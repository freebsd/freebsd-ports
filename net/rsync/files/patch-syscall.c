#
# enable copying of fifos/sockets
#  <http://lists.samba.org/archive/rsync/2002-June/002966.html>
#  <http://www.freebsd.org/cgi/query-pr.cgi?pr=59814>
#
--- syscall.c.orig	Wed Feb 18 23:33:21 2004
+++ syscall.c	Tue Aug 24 17:56:25 2004
@@ -76,6 +76,31 @@
 {
 	if (dry_run) return 0;
 	RETURN_ERROR_IF_RO_OR_LO;
+#if HAVE_MKFIFO
+	if (S_ISFIFO(mode))
+		return mkfifo(pathname, mode);
+#endif
+#if HAVE_SYS_UN_H
+	if (S_ISSOCK(mode)) {
+		int fd;
+		struct sockaddr_un *su;
+		size_t len;
+		if ((fd = socket(PF_UNIX, SOCK_STREAM, 0)) == -1)
+			return -1;
+		unlink(pathname);
+		len = sizeof(*su) - sizeof(su->sun_path) + strlen(pathname);
+		if ((su = calloc(1, len + 1)) == NULL)
+			return -1;
+		su->sun_len = len;
+		su->sun_family = AF_UNIX;
+		strcpy(su->sun_path, pathname);
+		if (bind(fd, (const struct sockaddr *)su, len) < 0)
+			return -1;
+		free(su);
+		close(fd);
+		return do_chmod(pathname, mode);
+	}
+#endif
 	return mknod(pathname, mode, dev);
 }
 #endif
