--- s_server.c.orig	2015-02-27 23:01:56.212257000 +0100
+++ s_server.c	2015-02-27 23:04:52.209584264 +0100
@@ -137,6 +137,9 @@
 , int keylen
 #endif
 );
+#if defined(OPENSSL_NO_SSL2)
+#define NO_SSL2
+#endif
 static int sv_body(char *hostname, int sin, int sout);
 static void close_accept_socket(void );
 static void sv_usage(void);
