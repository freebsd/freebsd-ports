--- usr/lib/pkcs11/api/socket_client.c.orig	2016-04-29 17:26:45 UTC
+++ usr/lib/pkcs11/api/socket_client.c
@@ -320,7 +320,7 @@ init_socket_data() {
 		return FALSE;
 	}
 
-	grp = getgrnam("pkcs11");
+	grp = getgrnam(PKCS11GROUP);
 	if ( !grp ) {
 		OCK_SYSLOG(LOG_ERR, "init_socket_data: pkcs11 group does not exist, errno=%d", errno);
 		return FALSE;
