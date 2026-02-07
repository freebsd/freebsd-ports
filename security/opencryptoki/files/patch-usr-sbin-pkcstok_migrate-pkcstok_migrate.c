--- usr/sbin/pkcstok_migrate/pkcstok_migrate.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcstok_migrate/pkcstok_migrate.c
@@ -20,7 +20,11 @@
 #include <errno.h>
 #include <getopt.h>
 #include <memory.h>
+#if !defined(__FreeBSD__)
 #include <linux/limits.h>
+#else
+#include <limits.h>
+#endif
 #include <openssl/evp.h>
 #include <string.h>
 #include <stdio.h>
@@ -2239,7 +2243,7 @@ static CK_RV change_owner(char *dir)
     CK_RV ret;
 
     /* Set group owner */
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp) {
         if (chown(dir, -1, grp->gr_gid)) {
             ret = CKR_FUNCTION_FAILED;
