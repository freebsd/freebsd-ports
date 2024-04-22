--- src/util/util_creds.h.orig	2023-05-05 08:11:07 UTC
+++ src/util/util_creds.h
@@ -73,6 +73,17 @@ struct cli_creds {
 #define cli_creds_get_uid(x) (x->ucred.uid)
 #define cli_creds_get_gid(x) (x->ucred.gid)
 
+#elif HAVE_FREEBSD
+#include <sys/param.h>
+#include <sys/ucred.h>
+struct cli_creds {
+    struct xucred ucred;
+    SELINUX_CTX selinux_ctx;
+};
+
+#define cli_creds_get_uid(x) (x->ucred.cr_uid)
+#define cli_creds_get_gid(x) (x->ucred.cr_gid)
+
 #else /* not HAVE_UCRED */
 struct cli_creds {
     SELINUX_CTX selinux_ctx;
