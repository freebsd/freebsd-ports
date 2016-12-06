--- pam_user_authorized_keys.c.orig	2016-11-13 03:24:32 UTC
+++ pam_user_authorized_keys.c
@@ -90,6 +90,10 @@ extern uint8_t allow_user_owned_authoriz
 
 uid_t authorized_keys_file_allowed_owner_uid;
 
+#ifndef HOST_NAME_MAX
+#define HOST_NAME_MAX	MAXHOSTNAMELEN
+#endif
+
 void
 parse_authorized_key_file(const char *user,
                           const char *authorized_keys_file_input)
