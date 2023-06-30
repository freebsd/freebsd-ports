--- src/responder/kcm/kcmsrv_ccache_secdb.c.orig	2023-05-05 08:11:07 UTC
+++ src/responder/kcm/kcmsrv_ccache_secdb.c
@@ -21,6 +21,9 @@
 
 #include "config.h"
 
+#include <sys/param.h>
+#include <sys/ucred.h>
+
 #include <talloc.h>
 #include <stdio.h>
 
@@ -877,8 +880,8 @@ static errno_t ccdb_secdb_get_cc_for_uuid(TALLOC_CTX *
             continue;
         }
 
-        cli_cred.ucred.uid = pwd->pw_uid;
-        cli_cred.ucred.gid = pwd->pw_gid;
+        cli_cred.ucred.cr_uid = pwd->pw_uid;
+        cli_cred.ucred.cr_gid = pwd->pw_gid;
 
         ret = key_by_uuid(tmp_ctx, secdb->sctx, &cli_cred, uuid, &secdb_key);
         if (ret != EOK) {
