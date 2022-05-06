--- usr/lib/tpm_stdll/tpm_specific.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/tpm_stdll/tpm_specific.c
@@ -3251,9 +3251,9 @@ int token_specific_creatlock(void)
                        "Directory(%s) missing: %s\n", lockdir, strerror(errno));
             goto err;
         }
-        grp = getgrnam("pkcs11");
+        grp = getgrnam(PKCS11GROUP);
         if (grp == NULL) {
-            fprintf(stderr, "getgrname(pkcs11): %s", strerror(errno));
+            fprintf(stderr, "getgrname(" PKCS11GROUP "): %s", strerror(errno));
             goto err;
         }
         /* set ownership to euid, and pkcs11 group */
