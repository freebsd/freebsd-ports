--- nss_module/nss_oslogin.cc.orig	2018-02-27 22:53:04 UTC
+++ nss_module/nss_oslogin.cc
@@ -16,6 +16,7 @@
 #include <errno.h>
 #include <grp.h>
 #include <nss.h>
+#include <nsswitch.h>
 #include <pthread.h>
 #include <pwd.h>
 #include <sys/types.h>
@@ -150,4 +151,27 @@ int _nss_oslogin_getpwent_r(struct passw
   }
   return NSS_STATUS_SUCCESS;
 }
+
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+
+static ns_mtab methods[] = {
+    { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, (void*)_nss_oslogin_getpwnam_r },
+    { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, (void*)_nss_oslogin_getpwuid_r },
+    { NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, (void*)_nss_oslogin_getpwent_r },
+    { NSDB_PASSWD, "endpwent",   __nss_compat_endpwent,   (void*)_nss_oslogin_endpwent },
+    { NSDB_PASSWD, "setpwent",   __nss_compat_setpwent,   (void*)_nss_oslogin_setpwent },
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
 }  // extern "C"
