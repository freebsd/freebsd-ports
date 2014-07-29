Index: plugins/ldapdb.c
diff -u -p plugins/ldapdb.c.orig plugins/ldapdb.c
--- plugins/ldapdb.c.orig	2011-05-12 04:25:55.000000000 +0900
+++ plugins/ldapdb.c	2011-09-24 17:25:23.465329876 +0900
@@ -251,6 +251,8 @@ static int ldapdb_auxprop_lookup(void *g
 
 #if defined(LDAP_PROXY_AUTHZ_FAILURE)
 	case LDAP_PROXY_AUTHZ_FAILURE:
+#else
+	case LDAP_X_PROXY_AUTHZ_FAILURE:
 #endif
 	case LDAP_INAPPROPRIATE_AUTH:
 	case LDAP_INVALID_CREDENTIALS:
