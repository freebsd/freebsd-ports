--- ./kernel/nthread.c.orig	2011-04-01 10:25:22.720654061 -0700
+++ ./kernel/nthread.c	2011-04-01 10:25:22.790651367 -0700
@@ -147,7 +147,7 @@
 	set_fs(oldfs);
 #else
 	uio_fill(&uio, iov, i, len, UIO_READ);
-	flags = MSG_WAITALL | MSG_NOSIGNAL;
+	flags = MSG_DONTWAIT | MSG_NOSIGNAL;
 	res = soreceive(conn->sock, NULL, &uio, NULL, NULL, &flags);
 	map_result(&res, &uio, len, 1);
 #endif
