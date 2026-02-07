--- usr/lib/common/pkcs_utils.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/pkcs_utils.c
@@ -466,7 +466,7 @@ void set_perm(int file)
     // Set absolute permissions or rw-rw----
     fchmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
 
-    grp = getgrnam("pkcs11"); // Obtain the group id
+    grp = getgrnam(PKCS11GROUP); // Obtain the group id
     if (grp) {
         // set ownership to pkcs11 group
         if (fchown(file, -1, grp->gr_gid) != 0) {
