--- src/authinfo_ldap.c.orig	2004-04-11 11:43:55 UTC
+++ src/authinfo_ldap.c
@@ -78,7 +78,16 @@ EXPORT int ldap_got_pass(char *pass)
 	
 	lderr = ldap_bind_s(ld, dnbuf, pass, LDAP_AUTH_SIMPLE);
 	if (lderr != LDAP_SUCCESS && lderr != LDAP_INVALID_CREDENTIALS && lderr != LDAP_INAPPROPRIATE_AUTH)
+#if LDAP_API_VERSION >= 2004
+	{
+		int ld_errno = 0;
+		ldap_get_option(ld, LDAP_OPT_ERROR_NUMBER, &ld_errno);
+		logen(("LDAP ERROR: ldap user bind failed (%d): %s", lderr, ldap_err2string(ld_errno)));
+	}
+#else
+
 		logen(("LDAP ERROR: ldap user bind failed (%d): %s", lderr, ldap_err2string(GET_LDERROR(ld))));
+#endif
 	ldap_unbind(ld);
 	memset(pass, strlen(pass), 0);
 	if (lderr == LDAP_SUCCESS) {
