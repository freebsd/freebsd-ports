--- servconf.c.orig	2010-06-25 17:38:45.000000000 -0600
+++ servconf.c	2010-09-14 16:14:12.000000000 -0600
@@ -139,7 +139,7 @@
 {
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* Standard Options */
 	if (options->protocol == SSH_PROTO_UNKNOWN)
@@ -170,7 +170,7 @@
 	if (options->key_regeneration_time == -1)
 		options->key_regeneration_time = 3600;
 	if (options->permit_root_login == PERMIT_NOT_SET)
-		options->permit_root_login = PERMIT_YES;
+		options->permit_root_login = PERMIT_NO;
 	if (options->ignore_rhosts == -1)
 		options->ignore_rhosts = 1;
 	if (options->ignore_user_known_hosts == -1)
@@ -180,7 +180,7 @@
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -218,7 +218,11 @@
 	if (options->gss_cleanup_creds == -1)
 		options->gss_cleanup_creds = 1;
 	if (options->password_authentication == -1)
+#ifdef USE_PAM
+		options->password_authentication = 0;
+#else
 		options->password_authentication = 1;
+#endif
 	if (options->kbd_interactive_authentication == -1)
 		options->kbd_interactive_authentication = 0;
 	if (options->challenge_response_authentication == -1)
