--- src/encrypt.cpp.orig	2011-09-28 11:15:10 UTC
+++ src/encrypt.cpp
@@ -175,10 +175,7 @@ net6::tcp_encrypted_socket_base::
                                   gnutls_session_t sess):
 	tcp_client_socket(cobj), session(sess), state(DEFAULT)
 {
-	const int kx_prio[] = { GNUTLS_KX_ANON_DH, 0 };
-
-	gnutls_set_default_priority(session);
-	gnutls_kx_set_priority(session, kx_prio);
+	gnutls_priority_set_direct(session, "NORMAL:-KX-ALL:+ANON-DH", NULL);
 
 	gnutls_transport_set_ptr(
 		session,
