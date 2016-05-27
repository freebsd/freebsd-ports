--- usr/sbin/pkcsconf/pkcsconf.c.orig	2016-04-29 17:26:46 UTC
+++ usr/sbin/pkcsconf/pkcsconf.c
@@ -777,6 +777,8 @@ display_pkcs11_info(void){
    printf("\tLibrary Version %d.%d \n", CryptokiInfo.libraryVersion.major,
          CryptokiInfo.libraryVersion.minor);
 
+   cleanup();
+
    return rc;
 }
 
