--- src/gp_creds.h.orig	2026-07-21 10:43:49 UTC
+++ src/gp_creds.h
@@ -7,15 +7,22 @@
 #include <stdint.h>
 #include <stdbool.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <gssapi/gssapi.h>
 
 #define CRED_TYPE_NONE 0x00
 #define CRED_TYPE_UNIX 0x01
 #define CRED_TYPE_SELINUX 0x02
 
+struct gp_unix_cred {
+    pid_t pid;
+    uid_t uid;
+    gid_t gid;
+};
+
 struct gp_creds {
     int type;
-    struct ucred ucred;
+    struct gp_unix_cred ucred;
 };
 
 #endif /* _GP_CREDS_H_ */
