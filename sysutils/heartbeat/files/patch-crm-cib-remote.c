--- crm/cib/remote.c.orig	2008-08-18 12:32:19 UTC
+++ crm/cib/remote.c
@@ -45,13 +45,6 @@ void cib_send_remote_msg(void *session, 
 
 #ifdef HAVE_GNUTLS_GNUTLS_H
 #  define DH_BITS 1024
-const int tls_kx_order[] = {
-	  GNUTLS_KX_ANON_DH,
-	  GNUTLS_KX_DHE_RSA,
-	  GNUTLS_KX_DHE_DSS,
-	  GNUTLS_KX_RSA,
-	0
-};
 gnutls_dh_params dh_params;
 gnutls_anon_server_credentials anon_cred;
 char *cib_send_tls(gnutls_session *session, HA_Message *msg);
@@ -83,8 +76,7 @@ create_tls_session(int csock)
 	session = (gnutls_session*)gnutls_malloc(sizeof(gnutls_session));
 
 	gnutls_init(session, GNUTLS_SERVER);
-	gnutls_set_default_priority(*session);
- 	gnutls_kx_set_priority (*session, tls_kx_order);
+ 	gnutls_priority_set_direct (*session, "NORMAL:-KX-ALL:+ANON-DH:+DHE-RSA:+DHE-DSS:+RSA", NULL);
 	gnutls_credentials_set(*session, GNUTLS_CRD_ANON, anon_cred);
 	gnutls_transport_set_ptr(*session,
 				 (gnutls_transport_ptr) GINT_TO_POINTER(csock));
