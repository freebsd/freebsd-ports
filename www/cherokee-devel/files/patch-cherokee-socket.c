--- cherokee/socket.c.orig	Tue Aug  2 05:32:12 2005
+++ cherokee/socket.c	Thu Aug  4 21:17:27 2005
@@ -1052,15 +1052,20 @@
 cherokee_socket_init_client_tls (cherokee_socket_t *socket)
 {
 #ifdef HAVE_TLS
-	int re;
-
-	socket->is_tls = TLS;
-
 # ifdef HAVE_GNUTLS
+
 	const int kx_priority[] = {GNUTLS_KX_ANON_DH, 0};
 
 	gnutls_anon_client_credentials   anoncred;
+
+# endif
+
+	int re;
 	
+	socket->is_tls = TLS;
+
+# ifdef HAVE_GNUTLS
+
 	/* Acredentials
 	 */
 	gnutls_anon_allocate_client_credentials(&anoncred);
