--- usr/sbin/pkcsslotd/shmem.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/sbin/pkcsslotd/shmem.c	2010-10-20 01:23:03.203984101 +0900
@@ -338,9 +338,9 @@
    }
    // SAB  Get the group information for the PKCS#11 group... fail if
    // it does not exist
-   grp = getgrnam("pkcs11");
+   grp = getgrnam(PKCS11GROUP);
    if ( !grp ) {
-     ErrLog("Group PKCS#11 does not exist ");
+     ErrLog("Group " PKCS11GROUP " does not exist ");
      return FALSE;  // Group does not exist... setup is wrong..
    }
 
@@ -409,9 +409,9 @@
    int i;
    char *buffer;
    
-   grp = getgrnam("pkcs11");
+   grp = getgrnam(PKCS11GROUP);
    if ( !grp ) {
-     ErrLog("Group \"pkcs11\" does not exist! Please run %s/pkcs11_startup.",
+     ErrLog("Group " PKCS11GROUP " does not exist! Please run %s/pkcs11_startup.",
 		     SBIN_PATH);
      return FALSE;  // Group does not exist... setup is wrong..
    }
@@ -431,7 +431,7 @@
 	 return FALSE;
        }
        if (fchown(fd, 0, grp->gr_gid) == -1) {
-	 ErrLog("%s: fchown(%s, root, pkcs11): %s", __FUNCTION__, MAPFILENAME,
+	 ErrLog("%s: fchown(%s, root, %s): %s", __FUNCTION__, MAPFILENAME, PKCS11GROUP,
 		strerror(errno));
 	 close(fd);
 	 return FALSE;
