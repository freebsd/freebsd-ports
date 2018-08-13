--- ldap-netgrp.c.orig	2016-06-05 21:43:56 UTC
+++ ldap-netgrp.c
@@ -161,6 +161,8 @@ struct __netgrent
   struct name_list *needed_groups;
 };
 
+size_t _nss_ldap_netgrent_sz = sizeof(struct __netgrent);
+
 static char *
 strip_whitespace (char *str)
 {
@@ -384,6 +386,19 @@ _nss_ldap_getnetgrent_r (struct __netgre
 {
   return _nss_ldap_parse_netgr (result, buffer, buflen);
 }
+
+enum nss_status
+_nss_ldap_netgrp_load_result (struct __netgrent *result,
+			      char **hostp, char **userp, char **domp)
+{
+
+  if (result->type == group_val)
+    return NSS_TRYAGAIN;
+  *hostp = result->val.triple.host;
+  *userp = result->val.triple.user;
+  *domp = result->val.triple.domain;
+  return NSS_SUCCESS;
+}
 #endif /* HAVE_NSS_H */
 
 #if defined(HAVE_NSSWITCH_H) || defined(HAVE_IRS_H)
