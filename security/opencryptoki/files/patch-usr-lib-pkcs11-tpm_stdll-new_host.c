--- usr/lib/pkcs11/tpm_stdll/new_host.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/tpm_stdll/new_host.c	2010-10-20 00:29:17.108984288 +0900
@@ -356,7 +356,7 @@
 		int   rc = 0;
 		int   index = 0;
 		gid_t  gid,egid;
-		grp = getgrnam("pkcs11");
+		grp = getgrnam(PKCS11GROUP);
 		if ( grp ) {
 			// Check for member of group..
 
