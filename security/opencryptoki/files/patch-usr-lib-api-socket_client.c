--- usr/lib/api/socket_client.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/api/socket_client.c
@@ -49,7 +49,7 @@ int connect_socket(const char *file_path)
         return -1;
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
         OCK_SYSLOG(LOG_ERR,
                    "connect_socket: pkcs11 group does not exist, errno=%d",
