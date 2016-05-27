--- usr/sbin/pkcsslotd/shmem.c.orig	2016-04-29 17:26:46 UTC
+++ usr/sbin/pkcsslotd/shmem.c
@@ -336,9 +336,9 @@ int CreateSharedMemory ( void ) {
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
 
@@ -415,9 +415,9 @@ int CreateSharedMemory ( void ) {
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
@@ -437,7 +437,7 @@ int CreateSharedMemory ( void ) {
 	 return FALSE;
        }
        if (fchown(fd, 0, grp->gr_gid) == -1) {
-	 ErrLog("%s: fchown(%s, root, pkcs11): %s", __FUNCTION__, MAPFILENAME,
+	 ErrLog("%s: fchown(%s, root, %s): %s", __FUNCTION__, MAPFILENAME, PKCS11GROUP,
 		strerror(errno));
 	 close(fd);
 	 return FALSE;
