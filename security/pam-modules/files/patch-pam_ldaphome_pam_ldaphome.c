--- pam_ldaphome/pam_ldaphome.c.orig	2021-01-06 16:15:09 UTC
+++ pam_ldaphome/pam_ldaphome.c
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <time.h>
+#include <signal.h>
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <ldap.h>
@@ -306,7 +307,7 @@
 static void ldap_unbind(LDAP *ld);
 
 static LDAP *
-ldap_connect(struct gray_env *env)
+pam_ldap_connect(struct gray_env *env)
 {
 	int rc;
 	char *ldapuri = NULL;
@@ -510,7 +511,7 @@
 }
 
 static int
-ldap_bind(LDAP *ld, struct gray_env *env)
+pam_ldap_bind(LDAP *ld, struct gray_env *env)
 {
 	int msgid, err, rc;
 	LDAPMessage *result;
@@ -594,7 +595,7 @@
 }
 
 static void
-ldap_unbind(LDAP *ld)
+pam_ldap_unbind(LDAP *ld)
 {
 	if (ld) {
 		ldap_set_option(ld, LDAP_OPT_SERVER_CONTROLS, NULL);
@@ -1579,10 +1580,10 @@
 	if (!attr)
 		attr = "sshPublicKey";
 	
-	ld = ldap_connect(env);
+	ld = pam_ldap_connect(env);
 	if (!ld)
 		return PAM_SERVICE_ERR;
-	if (ldap_bind(ld, env))
+	if (pam_ldap_bind(ld, env))
 		retval = PAM_SERVICE_ERR;
 	else {
 		char *filter;
@@ -1597,7 +1598,7 @@
 				retval = PAM_SUCCESS;
 		}
 	}
-	ldap_unbind(ld);
+	pam_ldap_unbind(ld);
 	return retval;
 }
 
