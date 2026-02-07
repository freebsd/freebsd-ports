--- usr/sbin/pkcsconf/pkcsconf.c.orig	2022-09-30 07:45:52 UTC
+++ usr/sbin/pkcsconf/pkcsconf.c
@@ -362,7 +362,7 @@ CK_RV check_user_and_group(void)
      * when forked). So we need to get the group information.
      * Really need to take the uid and map it to a name.
      */
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp == NULL) {
         return CKR_FUNCTION_FAILED;
     }
