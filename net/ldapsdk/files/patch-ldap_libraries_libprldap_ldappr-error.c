--- ldap/libraries/libprldap/ldappr-error.c.orig	2011-01-06 12:05:39 UTC
+++ ldap/libraries/libprldap/ldappr-error.c
@@ -231,7 +231,7 @@ struct prldap_errormap_entry {
 
 #if defined(__hpux) || defined(_AIX) || defined(OSF1) || defined(DARWIN) || \
   defined(BEOS) || defined(FREEBSD) || defined(BSDI) || defined(VMS) || \
-  defined(OPENBSD) || defined(NETBSD)
+  defined(OPENBSD) || defined(NETBSD) || defined(DRAGONFLY)
 #define EDEADLOCK       -1
 #endif
 
