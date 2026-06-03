r99048 | des | 2002-06-29 05:51:56 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/myproposal.h
   M /head/crypto/openssh/readconf.c
   M /head/crypto/openssh/servconf.c

Apply FreeBSD's configuration defaults.

--- servconf.c.orig	2026-04-25 16:05:26.936844000 -0700
+++ servconf.c	2026-04-25 16:18:06.486288000 -0700
@@ -298,7 +299,11 @@ fill_default_server_options(ServerOptions *options)
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+#ifdef USE_PAM
+		options->use_pam = 1;
+#else
+ 		options->use_pam = 0;
+#endif
 	if (options->pam_service_name == NULL)
 		options->pam_service_name = xstrdup(SSHD_PAM_SERVICE);
 
@@ -328,7 +333,7 @@ fill_default_server_options(ServerOptions *options)
 	if (options->login_grace_time == -1)
 		options->login_grace_time = 120;
 	if (options->permit_root_login == PERMIT_NOT_SET)
-		options->permit_root_login = PERMIT_NO_PASSWD;
+		options->permit_root_login = PERMIT_NO;
 	if (options->ignore_rhosts == -1)
 		options->ignore_rhosts = 1;
 	if (options->ignore_user_known_hosts == -1)
@@ -380,7 +385,11 @@ fill_default_server_options(ServerOptions *options)
 	if (options->gss_strict_acceptor == -1)
 		options->gss_strict_acceptor = 1;
 	if (options->password_authentication == -1)
+#ifdef USE_PAM
+		options->password_authentication = 0;
+#else
 		options->password_authentication = 1;
+#endif
 	if (options->kbd_interactive_authentication == -1)
 		options->kbd_interactive_authentication = 1;
 	if (options->permit_empty_passwd == -1)
