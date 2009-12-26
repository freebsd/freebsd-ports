--- pam_user_authorized_keys.c.orig	2009-11-07 03:47:20.000000000 +0100
+++ pam_user_authorized_keys.c	2009-12-26 12:49:29.000000000 +0100
@@ -81,6 +81,10 @@
 extern uint8_t  allow_user_owned_authorized_keys_file;
 uid_t           authorized_keys_file_allowed_owner_uid;
 
+#ifndef HOST_NAME_MAX
+#define HOST_NAME_MAX	MAXHOSTNAMELEN
+#endif
+
 void
 parse_authorized_key_file(const char *user, const char *authorized_keys_file_input)
 {
