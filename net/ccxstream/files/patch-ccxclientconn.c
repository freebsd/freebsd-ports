--- ccxclientconn.c.orig	2003-03-17 14:29:15 UTC
+++ ccxclientconn.c
@@ -51,6 +51,11 @@ static void cc_xstream_client_socket_set
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
