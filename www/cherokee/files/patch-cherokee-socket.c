--- cherokee/socket.c.orig	Wed Sep 13 21:48:51 2006
+++ cherokee/socket.c	Wed Sep 13 22:06:35 2006
@@ -1122,13 +1122,17 @@
 cherokee_socket_init_client_tls (cherokee_socket_t *socket)
 {
 #ifdef HAVE_TLS
-	int re;
-
 # ifdef HAVE_GNUTLS
+
 	const int                        kx_priority[] = {GNUTLS_KX_ANON_DH, 0};
 	gnutls_anon_client_credentials   anoncred;
-	
+
+#endif
+
+	int re;	
 	socket->is_tls = TLS;
+
+# ifdef HAVE_GNUTLS
 
 	/* Acredentials
 	 */
