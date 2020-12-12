--- src/util/nss_dl_load.c-orig	2020-10-22 17:57:10.433049000 +0100
+++ src/util/nss_dl_load.c	2020-11-01 13:25:22.636487000 +0000
@@ -24,6 +24,7 @@
 #include "util/util_errors.h"
 #include "util/debug.h"
 #include "nss_dl_load.h"
+#include "util/sss_bsd_errno.h"
 
 
 #define NSS_FN_NAME "_nss_%s_%s"
@@ -36,7 +37,8 @@
     char *funcname;
     void *funcptr;
 
-    funcname = talloc_asprintf(NULL, NSS_FN_NAME, libname, name);
+/*    funcname = talloc_asprintf(NULL, NSS_FN_NAME, libname, name);  */
+    funcname = talloc_asprintf(NULL, "%s", name);
     if (funcname == NULL) {
         DEBUG(SSSDBG_CRIT_FAILURE, "talloc_asprintf() failed\n");
         return NULL;
@@ -78,7 +80,8 @@
         {(void**)&ops->endservent,      "endservent"}
     };
 
-    libpath = talloc_asprintf(NULL, "libnss_%s.so.2", libname);
+/*    libpath = talloc_asprintf(NULL, "libnss_%s.so.2", libname); */
+    libpath = talloc_asprintf(NULL, "/lib/libc.so.7", libname);
     if (libpath == NULL) {
         DEBUG(SSSDBG_CRIT_FAILURE, "talloc_asprintf() failed\n");
         return ENOMEM;
