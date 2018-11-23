--- libnss_cache_oslogin/nss_cache_oslogin.c.orig	2018-10-11 16:53:23 UTC
+++ libnss_cache_oslogin/nss_cache_oslogin.c
@@ -16,6 +16,7 @@
 
 #include "nss_cache_oslogin.h"
 
+#include <nsswitch.h>
 #include <sys/mman.h>
 
 // Locking implementation: use pthreads.
@@ -32,7 +33,7 @@ static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZ
 
 static FILE *p_file = NULL;
 static char p_filename[NSS_CACHE_OSLOGIN_PATH_LENGTH] =
-    "/etc/oslogin_passwd.cache";
+    "%%PREFIX%%/etc/oslogin_passwd.cache";
 #ifdef BSD
 extern int fgetpwent_r(FILE *, struct passwd *, char *, size_t,
                        struct passwd **);
@@ -434,4 +435,27 @@ enum nss_status _nss_cache_oslogin_getpwnam_r(const ch
   NSS_CACHE_OSLOGIN_UNLOCK();
 
   return ret;
+}
+
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwnam_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwuid_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
+NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+
+static ns_mtab methods[] = {
+    { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, (void*)_nss_cache_oslogin_getpwnam_r },
+    { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, (void*)_nss_cache_oslogin_getpwuid_r },
+    { NSDB_PASSWD, "getpwent_r", __nss_compat_getpwent_r, (void*)_nss_cache_oslogin_getpwent_r },
+    { NSDB_PASSWD, "endpwent",   __nss_compat_endpwent,   (void*)_nss_cache_oslogin_endpwent },
+    { NSDB_PASSWD, "setpwent",   __nss_compat_setpwent,   (void*)_nss_cache_oslogin_setpwent },
+};
+
+ns_mtab *
+nss_module_register (const char *name, unsigned int *size,
+		                          nss_module_unregister_fn *unregister)
+{
+    *size = sizeof (methods) / sizeof (methods[0]);
+    *unregister = NULL;
+    return (methods);
 }
