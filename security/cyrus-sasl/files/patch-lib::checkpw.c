--- lib/checkpw.c.orig	Mon Jun 17 18:28:29 2002
+++ lib/checkpw.c	Mon Jun 17 18:31:44 2002
@@ -1667,12 +1667,14 @@
     return SASL_FAIL;
   }
   /* setting dereferensing aliases mode */
+#ifdef LDAP_OPT_DEREF
   if (ldap_set_option(ld, LDAP_OPT_DEREF, (void *) &ldap_deref) != LDAP_OPT_SUCCESS) {
     if (reply) {
       *reply = "cannot set deref options";
     }
     return SASL_FAIL;
   }
+#endif
   /* set ssl mode if needed */
 #ifdef LDAP_OPT_X_TLS
   if ( ldap_ssl_flag ) {
