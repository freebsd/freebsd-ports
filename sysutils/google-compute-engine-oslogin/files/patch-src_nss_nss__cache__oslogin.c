--- src/nss/nss_cache_oslogin.c.orig	2019-10-23 07:01:45 UTC
+++ src/nss/nss_cache_oslogin.c
@@ -439,7 +439,7 @@ DECLARE_NSS_METHOD_TABLE(methods,
     { NSDB_PASSWD, "getgrent_r", __nss_compat_getgrent_r,
       (void*)_nss_cache_oslogin_getgrent_r },
     { NSDB_PASSWD, "endgrent",   __nss_compat_endgrent,
-      (void*)_nss_cache_oslogin_endgrent },
+      (void*)_nss_cache_endgrent },
     { NSDB_PASSWD, "setgrent",   __nss_compat_setgrent,
       (void*)_nss_cache_oslogin_setgrent },
 )
