--- usr/lib/api/socket_client.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/api/socket_client.c
@@ -51,7 +51,7 @@ int init_socket_data()
         return FALSE;
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
         OCK_SYSLOG(LOG_ERR,
                    "init_socket_data: pkcs11 group does not exist, errno=%d",
