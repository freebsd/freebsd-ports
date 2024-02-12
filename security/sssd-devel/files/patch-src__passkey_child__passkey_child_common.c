--- src/passkey_child/passkey_child_common.c.orig	2024-01-12 12:05:40 UTC
+++ src/passkey_child/passkey_child_common.c
@@ -23,7 +23,6 @@
 */
 
 #include <popt.h>
-#include <sys/prctl.h>
 #include <fido/param.h>
 #include <openssl/err.h>
 #include <openssl/pem.h>
@@ -272,8 +271,6 @@ parse_arguments(TALLOC_CTX *mem_ctx, int argc, const c
     }
 
     poptFreeContext(pc);
-
-    prctl(PR_SET_DUMPABLE, (dumpable == 0) ? 0 : 1);
 
     if (user_verification != NULL) {
         if (strcmp(user_verification, "true") == 0) {
