--- servconf.c.orig	2013-05-12 21:26:30.642630751 -0500
+++ servconf.c	2013-05-12 21:52:43.069625377 -0500
@@ -162,7 +162,7 @@
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* Standard Options */
 	if (options->protocol == SSH_PROTO_UNKNOWN)
@@ -197,7 +197,7 @@
 	if (options->key_regeneration_time == -1)
 		options->key_regeneration_time = 3600;
 	if (options->permit_root_login == PERMIT_NOT_SET)
-		options->permit_root_login = PERMIT_YES;
+		options->permit_root_login = PERMIT_NO;
 	if (options->ignore_rhosts == -1)
 		options->ignore_rhosts = 1;
 	if (options->ignore_user_known_hosts == -1)
@@ -207,7 +207,7 @@
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -245,7 +245,11 @@
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
@@ -335,7 +339,7 @@
 		options->version_addendum = xstrdup("");
 	/* Turn privilege separation on by default */
 	if (use_privsep == -1)
-		use_privsep = PRIVSEP_NOSANDBOX;
+		use_privsep = PRIVSEP_ON;
 
 #ifndef HAVE_MMAP
 	if (use_privsep && options->compression == 1) {
