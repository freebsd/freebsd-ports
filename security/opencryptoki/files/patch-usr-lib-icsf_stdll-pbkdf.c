--- usr/lib/icsf_stdll/pbkdf.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/icsf_stdll/pbkdf.c
@@ -62,7 +62,7 @@ CK_RV set_perms(int file)
         return CKR_FUNCTION_FAILED;
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp) {
         if (fchown(file, -1, grp->gr_gid) != 0) {
             TRACE_ERROR("fchown failed: %s\n", strerror(errno));
