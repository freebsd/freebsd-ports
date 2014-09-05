--- src/ssl.h.orig
+++ src/ssl.h
@@ -1,12 +1,12 @@
 #ifdef ENABLE_SSL
 
-gnutls_session initialize_ssl_session(void);
+gnutls_session_t initialize_ssl_session(void);
 void check_ssl_alert( request* req, int ret);
 int send_alert(request * current);
 int finish_handshake(request * current);
 void ssl_regenerate_params(void);
 void generate_x509_dn(char *buf, int sizeof_buf,
-			const gnutls_datum * cert, int issuer);
+			const gnutls_datum_t * cert, int issuer);
 
 #endif
 
