--- lib/mgmt/mgmt_tls_lib.c.orig	2008-08-18 12:32:19 UTC
+++ lib/mgmt/mgmt_tls_lib.c
@@ -38,11 +38,6 @@ static gnutls_dh_params dh_params;
 gnutls_anon_server_credentials anoncred_server;
 gnutls_anon_client_credentials anoncred_client;
 
-const int kx_prio[] =
-{
-	GNUTLS_KX_ANON_DH,
-	0
-};
 
 int
 tls_init_client(void)
@@ -58,8 +53,7 @@ tls_attach_client(int sock)
 	int ret;
 	gnutls_session* session = (gnutls_session*)gnutls_malloc(sizeof(gnutls_session));
 	gnutls_init(session, GNUTLS_CLIENT);
-	gnutls_set_default_priority(*session);
-	gnutls_kx_set_priority (*session, kx_prio);
+	gnutls_priority_set_direct(*session, "NORMAL:-KX-ALL:+ANON-DH", NULL);
 	gnutls_credentials_set(*session, GNUTLS_CRD_ANON, anoncred_client);
 	gnutls_transport_set_ptr(*session, (gnutls_transport_ptr) GINT_TO_POINTER(sock));
 	ret = gnutls_handshake(*session);
@@ -131,8 +125,7 @@ tls_attach_server(int sock)
 	int ret;
 	gnutls_session* session = (gnutls_session*)gnutls_malloc(sizeof(gnutls_session));
 	gnutls_init(session, GNUTLS_SERVER);
-	gnutls_set_default_priority(*session);
-	gnutls_kx_set_priority (*session, kx_prio);
+	gnutls_priority_set_direct(*session, "NORMAL:-KX-ALL:+ANON-DH", NULL);
 	gnutls_credentials_set(*session, GNUTLS_CRD_ANON, anoncred_server);
 	gnutls_dh_set_prime_bits(*session, DH_BITS);
 	gnutls_transport_set_ptr(*session, (gnutls_transport_ptr) GINT_TO_POINTER(sock));
