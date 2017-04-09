--- ssl.c.orig	2016-03-27 13:46:35 UTC
+++ ssl.c
@@ -477,15 +477,14 @@ ssl_ssl_state_to_str(SSL *ssl)
 	int rv;
 
 	rv = asprintf(&str, "%08x = %s%s%s%04x = %s (%s) [%s]",
-	              ssl->state,
-	              (ssl->state & SSL_ST_CONNECT) ? "SSL_ST_CONNECT|" : "",
-	              (ssl->state & SSL_ST_ACCEPT) ? "SSL_ST_ACCEPT|" : "",
-	              (ssl->state & SSL_ST_BEFORE) ? "SSL_ST_BEFORE|" : "",
-	              ssl->state & SSL_ST_MASK,
+	              SSL_get_state(ssl),
+	              (SSL_get_state(ssl) & SSL_ST_CONNECT) ? "SSL_ST_CONNECT|" : "",
+	              (SSL_get_state(ssl) & SSL_ST_ACCEPT) ? "SSL_ST_ACCEPT|" : "",
+	              (SSL_get_state(ssl) & SSL_ST_BEFORE) ? "SSL_ST_BEFORE|" : "",
+	              SSL_get_state(ssl) & SSL_ST_MASK,
 	              SSL_state_string(ssl),
 	              SSL_state_string_long(ssl),
-	              (ssl->type == SSL_ST_CONNECT) ? "connect socket"
-	                                            : "accept socket");
+	              "");
 
 	return (rv < 0) ? NULL : str;
 }
