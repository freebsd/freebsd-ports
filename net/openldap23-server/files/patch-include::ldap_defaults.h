--- include/ldap_defaults.h.orig	Tue Sep 28 20:18:40 2004
+++ include/ldap_defaults.h	Tue Sep 28 20:20:01 2004
@@ -39,7 +39,7 @@
 #define LDAP_ENV_PREFIX "LDAP"
 
 /* default ldapi:// socket */
-#define LDAPI_SOCK LDAP_RUNDIR LDAP_DIRSEP "run" LDAP_DIRSEP "ldapi"
+#define LDAPI_SOCK "/var/run" LDAP_DIRSEP "openldap" LDAP_DIRSEP "ldapi"
 
 /*
  * SLAPD DEFINITIONS
