--- lib/ldapmap.c.orig	2018-03-16 04:58:17 UTC
+++ lib/ldapmap.c
@@ -201,7 +201,7 @@ ldap_map_free(int dbg, void *data)
 }
 
 
-static void ldap_unbind(LDAP *ld);
+static void eclat_ldap_unbind(LDAP *ld);
 
 static void
 dns2txtacc(struct grecs_txtacc *acc, LDAPURLDesc *lud)
@@ -353,7 +353,7 @@ ldap_connect(int dbg, struct ldap_map *map)
 			ldap_memfree(msg);
 
 			if (map->tls == tls_only) {
-				ldap_unbind(ld);
+				eclat_ldap_unbind(ld);
 				return NULL;
 			}
 			/* try to continue anyway */
@@ -365,7 +365,7 @@ ldap_connect(int dbg, struct ldap_map *map)
 }
 
 static int
-ldap_bind(int dbg, struct ldap_map *map)
+eclat_ldap_bind(int dbg, struct ldap_map *map)
 {
 	int msgid, ec, rc;
 	LDAPMessage *result;
@@ -441,7 +441,7 @@ ldap_bind(int dbg, struct ldap_map *map)
 }
 
 static void
-ldap_unbind(LDAP *ld)
+eclat_ldap_unbind(LDAP *ld)
 {
 	if (ld) {
 		ldap_set_option(ld, LDAP_OPT_SERVER_CONTROLS, NULL);
@@ -515,7 +515,7 @@ ldap_map_open(int dbg, void *data)
 	map->ld = ldap_connect(dbg, map);
 	if (!map->ld)
 		return eclat_map_failure;
-	if (ldap_bind(dbg, map))
+	if (eclat_ldap_bind(dbg, map))
 		return eclat_map_failure;
 	return eclat_map_ok;
 }
@@ -524,7 +524,7 @@ static int
 ldap_map_close(int dbg, void *data)
 {
 	struct ldap_map *map = data;
-	ldap_unbind(map->ld);
+	eclat_ldap_unbind(map->ld);
 	return 0;
 }
 
