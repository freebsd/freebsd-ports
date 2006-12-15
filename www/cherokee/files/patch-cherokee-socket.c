--- cherokee/socket.c.orig	Thu Dec  7 09:46:29 2006
+++ cherokee/socket.c	Thu Dec 14 10:35:48 2006
@@ -1153,13 +1153,17 @@
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
