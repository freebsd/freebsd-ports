--- lib/hdb/hdb-ldap.c.orig	Mon Apr 18 09:03:54 2005
+++ lib/hdb/hdb-ldap.c	Sat Oct  7 01:08:23 2006
@@ -1421,7 +1421,7 @@
     if (HDB2LDAP(db) != NULL) /* server is UP */
 	return 0;
 
-    rc = ldap_initialize(&((struct hdbldapdb *)db->hdb_db)->h_lp, "ldapi:///");
+    rc = ldap_initialize(&((struct hdbldapdb *)db->hdb_db)->h_lp, "ldapi://%%LDAP_SOCKET%%/");
     if (rc != LDAP_SUCCESS) {
 	krb5_set_error_string(context, "ldap_initialize: %s", 
 			      ldap_err2string(rc));
