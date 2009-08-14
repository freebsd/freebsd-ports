--- ./nss/prototypes.h.orig	2008-05-02 21:00:10.000000000 +0000
+++ ./nss/prototypes.h	2009-08-02 22:32:27.000000000 +0000
@@ -24,13 +24,40 @@
 #define _NSS_EXPORTS_H 1
 
 #include <nss.h>
-#include <aliases.h>
+#ifndef __FreeBSD__
 #include <netinet/ether.h>
+#else
+#include <net/ethernet.h>
+#include <sys/socket.h>
+#endif
 #include <sys/types.h>
 #include <grp.h>
 #include <netdb.h>
 #include <pwd.h>
+#ifdef HAVE_SHADOW_H
 #include <shadow.h>
+#endif
+
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
 
 /* We define struct etherent here because it does not seem to
    be defined in any publicly available header file exposed
@@ -160,10 +187,12 @@
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
