--- Modules/constants.c.orig	Sun Aug 13 16:00:59 2000
+++ Modules/constants.c	Mon Nov  6 11:02:43 2000
@@ -66,7 +66,6 @@
 	add_int(d,VERSION1);
 	add_int(d,VERSION2);
 	add_int(d,VERSION);
-	add_int(d,MAX_ATTR_LEN);
 	add_int(d,TAG_MESSAGE);
 	add_int(d,TAG_MSGID);
 
@@ -79,9 +78,27 @@
 	add_int(d,REQ_MODRDN);
 	add_int(d,REQ_COMPARE);
 	add_int(d,REQ_ABANDON);
+
+#if defined(LDAP_API_VERSION)
+	/* OpenLDAPv2 */
+	add_int(d,VERSION3);
+	add_int(d,VERSION_MIN);
+	add_int(d,VERSION_MAX);
+	add_int(d,TAG_LDAPDN);
+	add_int(d,TAG_LDAPCRED);
+	add_int(d,TAG_CONTROLS);
+	add_int(d,TAG_REFERRAL);
+
+	add_int(d,REQ_MODDN);
+	add_int(d,REQ_RENAME);
+#else
+	/* OpenLDAPv1 */
+	add_int(d,MAX_ATTR_LEN);
+
 	add_int(d,REQ_UNBIND_30);
 	add_int(d,REQ_DELETE_30);
 	add_int(d,REQ_ABANDON_30);
+#endif
 
 	/* reversibles */
 
@@ -89,6 +106,14 @@
 	PyDict_SetItem( reverse, zero, Py_None );
 	Py_DECREF( zero );
 
+#if defined(LDAP_API_VERSION)
+	/* OpenLDAPv2 */
+	add_int_r(d,RES_SEARCH_REFERENCE);
+	add_int_r(d,RES_MODDN);		/* Aliases for RES_MODRDN; */
+	add_int_r(d,RES_RENAME);	/* init them before the main name */
+	add_int(d,RES_UNSOLICITED);
+#endif
+
 	add_int_r(d,RES_BIND);
 	add_int_r(d,RES_SEARCH_ENTRY);
 	add_int_r(d,RES_SEARCH_RESULT);
@@ -106,9 +131,6 @@
 	add_int(d,AUTH_KRBV4);
 	add_int(d,AUTH_KRBV41);
 	add_int(d,AUTH_KRBV42);
-	add_int(d,AUTH_SIMPLE_30);
-	add_int(d,AUTH_KRBV41_30);
-	add_int(d,AUTH_KRBV42_30);
 	add_int(d,FILTER_AND);
 	add_int(d,FILTER_OR);
 	add_int(d,FILTER_NOT);
@@ -118,13 +140,9 @@
 	add_int(d,FILTER_LE);
 	add_int(d,FILTER_PRESENT);
 	add_int(d,FILTER_APPROX);
-	add_int(d,FILTER_PRESENT_30);
 	add_int(d,SUBSTRING_INITIAL);
 	add_int(d,SUBSTRING_ANY);
 	add_int(d,SUBSTRING_FINAL);
-	add_int(d,SUBSTRING_INITIAL_30);
-	add_int(d,SUBSTRING_ANY_30);
-	add_int(d,SUBSTRING_FINAL_30);
 	add_int(d,SCOPE_BASE);
 	add_int(d,SCOPE_ONELEVEL);
 	add_int(d,SCOPE_SUBTREE);
@@ -133,6 +151,16 @@
 	add_int(d,MOD_REPLACE);
 	add_int(d,MOD_BVALUES);
 
+#if !defined(LDAP_API_VERSION)
+	/* OpenLDAPv1 */
+	add_int(d,AUTH_SIMPLE_30);
+	add_int(d,AUTH_KRBV41_30);
+	add_int(d,AUTH_KRBV42_30);
+	add_int(d,FILTER_PRESENT_30);
+	add_int(d,SUBSTRING_INITIAL_30);
+	add_int(d,SUBSTRING_ANY_30);
+	add_int(d,SUBSTRING_FINAL_30);
+
 	/* (errors.c contains the error constants) */
 
 	add_int(d,DEFAULT_REFHOPLIMIT);
@@ -145,15 +173,36 @@
 #ifdef LDAP_CACHE_OPT_CACHEALLERRS
 	add_int(d,CACHE_OPT_CACHEALLERRS);
 #endif
+
+#endif	/* !defined(LDAP_API_VERSION) */
 	add_int(d,FILT_MAXSIZ);
 	add_int(d,DEREF_NEVER);
 	add_int(d,DEREF_SEARCHING);
 	add_int(d,DEREF_FINDING);
 	add_int(d,DEREF_ALWAYS);
 	add_int(d,NO_LIMIT);
+#if defined(LDAP_API_VERSION)
+	/* OpenLDAPv2 */
+	add_int(d,OPT_API_INFO);
+	add_int(d,OPT_DESC);
+	add_int(d,OPT_DEREF);
+	add_int(d,OPT_SIZELIMIT);
+	add_int(d,OPT_TIMELIMIT);
+	add_int(d,OPT_PROTOCOL_VERSION);
+	add_int(d,OPT_SERVER_CONTROLS);
+	add_int(d,OPT_CLIENT_CONTROLS);
+	add_int(d,OPT_API_FEATURE_INFO);
+	add_int(d,OPT_HOST_NAME);
+	add_int(d,OPT_ERROR_NUMBER);
+	add_int(d,OPT_ERROR_STRING);
+	add_int(d,OPT_MATCHED_DN);
+	add_int(d,OPT_PRIVATE_EXTENSION_BASE);
+#else
+	/* OpenLDAPv1 */
 #ifdef LDAP_OPT_DNS
 	add_int(d,OPT_DNS);
 #endif
+#endif /* defined(LDAP_API_VERSION) */
 #ifdef LDAP_OPT_REFERRALS
 	add_int(d,OPT_REFERRALS);
 #endif
@@ -161,9 +210,24 @@
 
 	/* XXX - these belong in errors.c */
 
+#if defined(LDAP_API_VERSION)
+	/* OpenLDAPv2 */
+	add_int(d,URL_SUCCESS);
+	add_int(d,URL_ERR_PARAM);
+	add_int(d,URL_ERR_BADSCHEME);
+	add_int(d,URL_ERR_BADENCLOSURE);
+	add_int(d,URL_ERR_BADURL);
+	add_int(d,URL_ERR_BADHOST);
+	add_int(d,URL_ERR_BADATTRS);
+	add_int(d,URL_ERR_BADSCOPE);
+	add_int(d,URL_ERR_BADFILTER);
+	add_int(d,URL_ERR_BADEXTS);
+#else
+	/* OpenLDAPv1 */
 	add_int(d,URL_ERR_NOTLDAP);
 	add_int(d,URL_ERR_NODN);
 	add_int(d,URL_ERR_BADSCOPE);
+#endif /* defined(LDAP_API_VERSION) */
 	add_int(d,URL_ERR_MEM);
 
 	/* author */
