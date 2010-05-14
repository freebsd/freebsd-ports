--- nss/prototypes.h.orig	2009-09-04 15:55:35.000000000 +0400
+++ nss/prototypes.h	2009-12-20 15:37:57.000000000 +0300
@@ -84,6 +86,27 @@
   void *nip; /* changed from `service_user *nip' */
 };
 
+#ifdef __FreeBSD__
+/* 
+ * Import from aliases.h
+ */
+struct aliasent
+  {
+    char *alias_name;
+    size_t alias_members_len;
+    char **alias_members;
+    int alias_local;
+  };
+
+struct rpcent
+{
+  char *r_name;         /* Name of server for this rpc program.  */
+  char **r_aliases;     /* Alias list.  */
+  int r_number;         /* RPC program number.  */
+};
+
+#endif
+
 /*
    These are prototypes for functions exported from the ldap NSS module.
    For more complete definitions of these functions check the GLIBC
@@ -166,10 +189,12 @@
 enum nss_status _nss_ldap_getservent_r(struct servent *result,char *buffer,size_t buflen,int *errnop);
 enum nss_status _nss_ldap_endservent(void);
 
+#ifdef HAVE_SHADOW_H
 /* shadow - extended user information */
 enum nss_status _nss_ldap_getspnam_r(const char *name,struct spwd *result,char *buffer,size_t buflen,int *errnop);
 enum nss_status _nss_ldap_setspent(int stayopen);
 enum nss_status _nss_ldap_getspent_r(struct spwd *result,char *buffer,size_t buflen,int *errnop);
 enum nss_status _nss_ldap_endspent(void);
+#endif
 
 #endif /* not NSS_EXPORTS */
