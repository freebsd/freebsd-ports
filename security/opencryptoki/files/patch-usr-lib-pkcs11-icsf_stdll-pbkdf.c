--- usr/lib/pkcs11/icsf_stdll/pbkdf.c.orig	2016-04-29 17:26:46 UTC
+++ usr/lib/pkcs11/icsf_stdll/pbkdf.c
@@ -337,7 +337,7 @@ set_perms(int file)
 		return CKR_FUNCTION_FAILED;
 	}
 
-	grp = getgrnam("pkcs11");
+	grp = getgrnam(PKCS11GROUP);
 	if (grp) {
 		if (fchown(file, -1, grp->gr_gid) != 0) {
 			TRACE_ERROR("fchown failed: %s\n", strerror(errno));
