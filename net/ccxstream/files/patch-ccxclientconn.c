--- ccxclientconn.c.orig	Mon Mar 17 11:29:15 2003
+++ ccxclientconn.c	Tue May 15 14:58:52 2007
@@ -51,6 +51,11 @@
   i = 1;
   setsockopt(sock, IPPROTO_TCP,TCP_NODELAY, &i, sizeof (i));
 #endif /* TCP_NODELAY */
+
+#ifdef SO_KEEPALIVE
+  i = 1;
+  setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &i, sizeof (i));
+#endif /* SO_KEEPALIVE */
 }
 
 CcXstreamClientError cc_xstream_client_connect(const char *host,
