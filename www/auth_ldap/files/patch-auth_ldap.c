--- auth_ldap.c.orig	Mon Jan  9 20:08:56 2006
+++ auth_ldap.c	Tue Mar 14 19:12:02 2006
@@ -168,11 +168,7 @@
     ap_log_rerror(APLOG_MARK, APLOG_DEBUG|APLOG_NOERRNO, r,
 		  "{%d} LDAP OP: init", (int)getpid());
 
-#if defined(WITH_OPENLDAP) && LDAP_VENDOR_VERSION >= 20000
-    if ((ldap_initialize(&(sec->ldc->ldap), (sec->url))) != LDAP_SUCCESS) {
-#else
     if ((sec->ldc->ldap = ldap_init(sec->host, sec->port)) == NULL) {
-#endif
       extern int errno;
       auth_ldap_log_reason(r, "Could not connect to LDAP server: %s", strerror(errno));
       return 0;
