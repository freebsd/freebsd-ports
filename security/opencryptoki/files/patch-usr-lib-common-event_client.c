--- usr/lib/common/event_client.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/event_client.c
@@ -32,7 +32,7 @@ static int connect_socket(const char *file_path)
     if (stat(file_path, &file_info))
         return -errno;
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp)
         return -errno;
 
