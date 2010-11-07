--- usr/lib/pkcs11/tpm_stdll/loadsave.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/tpm_stdll/loadsave.c	2010-10-20 00:27:47.109983972 +0900
@@ -339,7 +339,7 @@
    fchmod(file,S_IRUSR|S_IWUSR);
 
 #if 0
-   grp = getgrnam("pkcs11"); // Obtain the group id
+   grp = getgrnam(PKCS11GROUP); // Obtain the group id
    if (grp){
       fchown(file,getuid(),grp->gr_gid);  // set ownership to root, and pkcs11 group
    }
