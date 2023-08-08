--- src/util/nss_dl_load.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/nss_dl_load.c
@@ -24,6 +24,7 @@
 #include "util/util_errors.h"
 #include "util/debug.h"
 #include "nss_dl_load.h"
+#include "util/sss_bsd_errno.h"
 
 
 #define NSS_FN_NAME "_nss_%s_%s"
@@ -36,7 +37,7 @@ static void *proxy_dlsym(void *handle,
     char *funcname;
     void *funcptr;
 
-    funcname = talloc_asprintf(NULL, NSS_FN_NAME, libname, name);
+    funcname = talloc_asprintf(NULL, "%s", name);
     if (funcname == NULL) {
         DEBUG(SSSDBG_CRIT_FAILURE, "talloc_asprintf() failed\n");
         return NULL;
@@ -56,7 +57,7 @@ errno_t sss_load_nss_symbols(struct sss_nss_ops *ops, 
     char *libpath;
     size_t i;
 
-    libpath = talloc_asprintf(NULL, "libnss_%s.so.2", libname);
+    libpath = talloc_asprintf(NULL, "/lib/libc.so.7", libname);
     if (libpath == NULL) {
         DEBUG(SSSDBG_CRIT_FAILURE, "talloc_asprintf() failed\n");
         return ENOMEM;
