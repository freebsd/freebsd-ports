--- servers/slapd/back-ldap/search.c	Thu Jan 20 18:01:12 2005
+++ servers/slapd/back-ldap/search.c	Wed Feb  2 14:51:05 2005
@@ -681,7 +681,7 @@
 
 retry:
 	rc = ldap_search_ext_s(lc->ld, mdn.bv_val, LDAP_SCOPE_BASE, filter,
-				gattr, 0, NULL, NULL, LDAP_NO_LIMIT,
+				at ? gattr : NULL, 0, NULL, NULL, LDAP_NO_LIMIT,
 				LDAP_NO_LIMIT, &result);
 	if ( rc != LDAP_SUCCESS ) {
 		if ( rc == LDAP_SERVER_DOWN && do_retry ) {
