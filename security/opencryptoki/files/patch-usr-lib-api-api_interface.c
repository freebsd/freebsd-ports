--- usr/lib/api/api_interface.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/api/api_interface.c
@@ -373,7 +373,7 @@ static CK_RV check_user_and_group()
      * when forked). So we need to get the group information.
      * Really need to take the uid and map it to a name.
      */
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp == NULL) {
         OCK_SYSLOG(LOG_ERR, "getgrnam() failed: %s\n", strerror(errno));
         goto error;
