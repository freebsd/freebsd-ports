--- usr/sbin/pkcsconf/pkcsconf.c.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsconf/pkcsconf.c
@@ -530,6 +530,8 @@ CK_RV display_pkcs11_info(void)
     printf("\tLibrary Version %d.%d \n", CryptokiInfo.libraryVersion.major,
            CryptokiInfo.libraryVersion.minor);
 
+    cleanup();
+
     return rc;
 }
 
