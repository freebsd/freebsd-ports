--- src/interface.c.orig	2015-12-21 07:49:44 UTC
+++ src/interface.c
@@ -285,3 +285,57 @@ _nss_pgsql_getspnam_r(const char *spnam,
 
 	return retval;
 }
+
+/* Thanks to Clement Laforet for most of this */
+#if defined(__FreeBSD__)
+
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrnam_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrgid_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getgrent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_setgrent);
+NSS_METHOD_PROTOTYPE(__nss_compat_endgrent);
+
+enum nss_status _nss_pgsql_getpwnam_r (const char *, struct passwd *, char *,
+                                  size_t, int *);
+enum nss_status _nss_pgsql_getpwuid_r (uid_t, struct passwd *, char *,
+                                  size_t, int *);
+enum nss_status _nss_pgsql_getpwent_r (struct passwd *, char *, size_t, int *);
+enum nss_status _nss_pgsql_setpwent (void);
+enum nss_status _nss_pgsql_endpwent (void);
+
+enum nss_status _nss_pgsql_getgrnam_r (const char *, struct group *, char *,
+                                  size_t, int *);
+enum nss_status _nss_pgsql_getgrgid_r (gid_t, struct group *, char *,
+                                  size_t, int *);
+enum nss_status _nss_pgsql_getgrent_r (struct group *, char *, size_t, int *);
+enum nss_status _nss_pgsql_setgrent (void);
+enum nss_status _nss_pgsql_endgrent (void);
+
+static ns_mtab methods[] = {
+    { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, _nss_pgsql_getpwnam_r },
+    { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, _nss_pgsql_getpwuid_r },
+    { NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, _nss_pgsql_getpwent_r },
+    { NSDB_PASSWD, "endpwent",   __nss_compat_setpwent,   _nss_pgsql_setpwent },
+    { NSDB_PASSWD, "setpwent",   __nss_compat_endpwent,   _nss_pgsql_endpwent },
+    { NSDB_GROUP,  "getgrnam_r", __nss_compat_getgrnam_r, _nss_pgsql_getgrnam_r },
+    { NSDB_GROUP,  "getgrgid_r", __nss_compat_getgrgid_r, _nss_pgsql_getgrgid_r },
+    { NSDB_GROUP,  "getgrent_r", __nss_compat_getgrent_r, _nss_pgsql_getgrent_r },
+    { NSDB_GROUP,  "endgrent",   __nss_compat_setgrent,   _nss_pgsql_setgrent },
+    { NSDB_GROUP,  "setgrent",   __nss_compat_endgrent,   _nss_pgsql_endgrent },
+};
+
+ns_mtab *
+nss_module_register (const char *name, unsigned int *size,
+                     nss_module_unregister_fn *unregister)
+{
+    *size = sizeof (methods) / sizeof (methods[0]);
+    *unregister = NULL;
+    return (methods);
+}
+
+#endif /* defined(__FreeBSD__) */
