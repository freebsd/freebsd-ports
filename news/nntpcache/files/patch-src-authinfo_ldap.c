--- src/authinfo_ldap.c.orig	Sat Dec 18 12:08:30 1999
+++ src/authinfo_ldap.c	Wed Sep 26 10:55:27 2001
@@ -78,7 +78,16 @@
 	
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
