--- s_server.c.orig	2000-11-11 22:11:18 UTC
+++ s_server.c
@@ -137,6 +137,12 @@ static RSA MS_CALLBACK *tmp_rsa_cb(SSL *
 , int keylen
 #endif
 );
+#if defined(OPENSSL_NO_SSL2)
+#define NO_SSL2
+#endif
+#if defined(OPENSSL_NO_SSL3)
+#define NO_SSL3
+#endif
 static int sv_body(char *hostname, int sin, int sout);
 static void close_accept_socket(void );
 static void sv_usage(void);
