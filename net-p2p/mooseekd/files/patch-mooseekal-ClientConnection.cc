--- mooseekal/ClientConnection.cc.orig	Sun Jul 30 10:18:08 2006
+++ mooseekal/ClientConnection.cc	Sun Jul 30 10:20:02 2006
@@ -228,7 +228,12 @@
 			outbuf.pop();
 		}
 
+// FreeBSD 5.x and older doesn't support MSG_NOSIGNAL
+#ifdef MSG_NOSIGNAL
 		j = ::send (sock, data, i, MSG_NOSIGNAL);
+#else
+		j = ::send (sock, data, i, 0);
+#endif // MSG_NOSIGNAL
 
 		errno = 0;
 		if (j < 0) {
