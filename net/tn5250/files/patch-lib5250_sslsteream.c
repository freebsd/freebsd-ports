$OpenBSD: patch-src_sslstream_c,v 1.2 2015/07/18 04:59:42 sthen Exp $

Allow building against OpenSSL without SSLv2/SSLv3 support.

--- lib5250/sslstream.c.orig	2008-11-21 09:12:21.000000000 +0100
+++ lib5250/sslstream.c	2015-09-10 16:40:30.723087282 +0200
@@ -368,13 +368,19 @@ int tn5250_ssl_stream_init (Tn5250Stream
         methstr[4] = '\0';
    }
 
+#ifndef OPENSSL_NO_SSL2
    if (!strcmp(methstr, "ssl2")) {
         meth = SSLv2_client_method();         
         TN5250_LOG(("SSL Method = SSLv2_client_method()\n"));
-   } else if (!strcmp(methstr, "ssl3")) {
+   } else
+#endif
+#ifndef OPENSSL_NO_SSL3
+   if (!strcmp(methstr, "ssl3")) {
         meth = SSLv3_client_method();         
         TN5250_LOG(("SSL Method = SSLv3_client_method()\n"));
-   } else {
+   } else 
+#endif
+   {
         meth = SSLv23_client_method();         
         TN5250_LOG(("SSL Method = SSLv23_client_method()\n"));
    }
