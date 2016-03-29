--- common/common.c.orig	2006-12-21 14:08:50 UTC
+++ common/common.c
@@ -271,8 +271,6 @@ TLSSOCKET sock_alloc(void);
 TLSSOCKET sock_alloc(void)
 {
 #ifdef AICCU_GNUTLS
-	/* Allow connections to servers that have OpenPGP keys as well */
-	const int	cert_type_priority[3] = { GNUTLS_CRT_X509, GNUTLS_CRT_OPENPGP, 0 };
 	int		ret;
 #endif /* AICCU_GNUTLS*/
 
@@ -296,11 +294,8 @@ TLSSOCKET sock_alloc(void)
 		return NULL;
 	}
 
-	/* Use default priorities */
-	gnutls_set_default_priority(sock->session);
-	/* XXX: Return value is not documented in GNUTLS documentation! */
-
-	gnutls_certificate_type_set_priority(sock->session, cert_type_priority);
+	/* Allow connections to servers that have OpenPGP keys as well */
+	gnutls_priority_set_direct(sock->session, "NORMAL:+CTYPE-OPENPGP", NULL);
 	/* XXX: Return value is not documented in GNUTLS documentation! */
 
 	/* Configure the x509 credentials for the current session */
