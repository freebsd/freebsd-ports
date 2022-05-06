--- usr/lib/api/policy.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/api/policy.c
@@ -1178,10 +1178,10 @@ static CK_RV policy_check_cfg_file(FILE *fp, const cha
     struct group *grp = NULL;
     int err;
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
-        TRACE_ERROR("Could not retrieve \"pkcs11\" group!");
-        OCK_SYSLOG(LOG_ERR, "POLICY: Could not retrieve \"pkcs11\" group!");
+        TRACE_ERROR("Could not retrieve \"" PKCS11GROUP "\" group!");
+        OCK_SYSLOG(LOG_ERR, "POLICY: Could not retrieve \"" PKCS11GROUP "\" group!");
         return CKR_GENERAL_ERROR;
     }
     if (fstat(fileno(fp), &statbuf)) {
@@ -1200,16 +1200,17 @@ static CK_RV policy_check_cfg_file(FILE *fp, const cha
         return CKR_GENERAL_ERROR;
     }
     if (statbuf.st_gid != grp->gr_gid) {
-        TRACE_ERROR("Policy configuration file %s should have group \"pkcs11\"!\n",
+        TRACE_ERROR("Policy configuration file %s should have group \"" PKCS11GROUP "\"!\n",
                     name);
-        OCK_SYSLOG(LOG_ERR, "POLICY: Configuration file %s should have group \"pkcs11\"!\n",
+        OCK_SYSLOG(LOG_ERR, "POLICY: Configuration file %s should have group \"" PKCS11GROUP "\"!\n",
                    name);
         return CKR_GENERAL_ERROR;
     }
     if ((statbuf.st_mode & ~S_IFMT) != OCK_POLICY_PERMS) {
-        TRACE_ERROR("Configuration file %s has wrong permissions!\n", name);
-        OCK_SYSLOG(LOG_ERR, "POLICY: Configuration file %s has wrong permissions!\n",
-                   name);
+        TRACE_ERROR("Configuration file %s must have %04o permission (was %04o)\n",
+            name, OCK_POLICY_PERMS, (statbuf.st_mode & ~S_IFMT));
+        OCK_SYSLOG(LOG_ERR, "POLICY: Configuration file %s must have %04o permission (is %04o)\n",
+            name, OCK_POLICY_PERMS, (statbuf.st_mode & ~S_IFMT));
         return CKR_GENERAL_ERROR;
     }
     return CKR_OK;
