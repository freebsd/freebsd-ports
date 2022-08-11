--- usr/sbin/pkcsconf/pkcsconf.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcsconf/pkcsconf.c
@@ -548,7 +548,7 @@ CK_RV check_user_and_group(void)
      * when forked). So we need to get the group information.
      * Really need to take the uid and map it to a name.
      */
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp == NULL) {
         return CKR_FUNCTION_FAILED;
     }
@@ -589,6 +589,8 @@ CK_RV display_pkcs11_info(void)
     printf("\tLibrary Description: %.32s \n", CryptokiInfo.libraryDescription);
     printf("\tLibrary Version: %d.%d \n", CryptokiInfo.libraryVersion.major,
            CryptokiInfo.libraryVersion.minor);
+
+    cleanup();
 
     return rc;
 }
