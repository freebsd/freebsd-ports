--- lib/checkpw.c.orig	Fri Jan 18 21:56:29 2002
+++ lib/checkpw.c	Fri Jan 18 22:14:58 2002
@@ -1491,6 +1491,9 @@
 # define FALSE         0
 #endif
 
+#ifndef LDAP_NO_ATTRS
+#define LDAP_NO_ATTRS	"1.1"
+#endif
 static int ldap_isdigits(char *value)
 {
   char *ptr;
@@ -1504,6 +1507,16 @@
   return num;
 }
 
+#ifdef LDAP_VENDOR_VERSION
+#define SASL_ldap_search_ext_s(ld, base, scope, filter, attrs, attrsonly, serverctrls, clientctrls, timeout, sizelimit, res) \
+	ldap_search_ext_s(ld, base, scope, filter, attrs, attrsonly, serverctrls, clientctrls, timeout, sizelimit, res)
+#define SASL_ldap_memfree(dn) ldap_memfree(dn)
+#else
+#define SASL_ldap_search_ext_s(ld, base, scope, filter, attrs, attrsonly, serverctrls, clientctrls, timeout, sizelimit, res) \
+	 ldap_search_st(ld, base, scope, filter, attrs, attrsonly, timeout, res)
+#define SASL_ldap_memfree(dn) free(dn)
+#endif
+
 static int ldap_verify_password(sasl_conn_t *conn,
 				const char *userid,
 				const char *password,
@@ -1522,18 +1535,18 @@
     *ldap_filter="",
     *ldap_bind_dn="",
     *ldap_bind_pw="",
-    *ldap_ssl="",
     *ldap_filter_mode="",
     *port_num="";
   int malloc_size; /* safety net */
   int ldap_filter_flag = 0;
-  int ldap_ssl_flag = 0;
   int ldap_port = LDAP_PORT;
   sasl_getopt_t *getopt;
   void *context;
   LDAPMessage	*result, *e;
   char *attrs[]={LDAP_NO_ATTRS, NULL};
 #ifdef LDAP_OPT_X_TLS
+  char *ldap_ssl="";
+  int ldap_ssl_flag = 0;
   int tls_option;
 #endif
   
@@ -1625,9 +1638,11 @@
     return SASL_FAIL;
   }
   /* set ssl mode if needed */
+#ifdef LDAP_OPT_X_TLS
   if ( ldap_ssl_flag ) {
     ldap_set_option(ld, LDAP_OPT_X_TLS, (void *)&tls_option);  
   }
+#endif
   
   /* either run the filter or just bind as them ? */
   
@@ -1657,7 +1672,7 @@
     snprintf(filter,malloc_size-1,"(&(%s=%s)%s)", ldap_uidattr, userid, ldap_filter);
     
     /* Now do the search */
-    if (ldap_search_ext_s(ld, ldap_basedn, LDAP_SCOPE_SUBTREE, filter,
+    if (SASL_ldap_search_ext_s(ld, ldap_basedn, LDAP_SCOPE_SUBTREE, filter,
                           attrs, 0, NULL, NULL, LDAP_NO_LIMIT, 1, &result) !=
 	LDAP_SUCCESS) {
       free(filter);
@@ -1680,17 +1695,17 @@
       ldap_unbind(ld);
       return SASL_BADAUTH;
     }
-    if (ldap_simple_bind_s(ld,dn,password) != LDAP_SUCCESS) {
+    if (ldap_simple_bind_s(ld,dn,(char *)password) != LDAP_SUCCESS) {
       e = NULL;
       free(filter);
-      ldap_memfree(dn);
+      SASL_ldap_memfree(dn);
       ldap_msgfree(result);
       ldap_unbind(ld);
       return SASL_BADAUTH;
     }
     e = NULL;
     free(filter);
-    ldap_memfree(dn);
+    SASL_ldap_memfree(dn);
     ldap_msgfree(result);
     
   } else {
@@ -1710,7 +1725,7 @@
    * If this is not so I have a version or that too
    * Simon@surf.org.uk
    */
-    if (ldap_simple_bind_s(ld,dn,password) != LDAP_SUCCESS) {
+    if (ldap_simple_bind_s(ld,dn,(char *)password) != LDAP_SUCCESS) {
       free(dn);
       ldap_unbind(ld);
       return SASL_BADAUTH;
