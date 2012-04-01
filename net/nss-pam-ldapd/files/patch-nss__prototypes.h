--- nss/prototypes.h.orig	2011-03-09 13:39:24.000000000 -0900
+++ nss/prototypes.h	2012-02-29 17:15:19.000000000 -0900
@@ -125,11 +125,13 @@
 nss_status_t _nss_ldap_getservent_r(struct servent *result,char *buffer,size_t buflen,int *errnop);
 nss_status_t _nss_ldap_endservent(void);
 
+#ifdef HAVE_SHADOW_H
 /* shadow - extended user information */
 nss_status_t _nss_ldap_getspnam_r(const char *name,struct spwd *result,char *buffer,size_t buflen,int *errnop);
 nss_status_t _nss_ldap_setspent(int stayopen);
 nss_status_t _nss_ldap_getspent_r(struct spwd *result,char *buffer,size_t buflen,int *errnop);
 nss_status_t _nss_ldap_endspent(void);
+#endif
 
 #endif /* NSS_FLAVOUR_GLIBC */
 
