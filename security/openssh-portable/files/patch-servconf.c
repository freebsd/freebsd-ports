--- servconf.c.orig	2015-03-22 22:16:53.563005000 -0500
+++ servconf.c	2015-03-22 22:19:39.207917000 -0500
@@ -54,6 +54,7 @@
 #include "packet.h"
 #include "hostfile.h"
 #include "auth.h"
+#include "version.h"
 
 static void add_listen_addr(ServerOptions *, char *, int);
 static void add_one_listen_addr(ServerOptions *, char *, int);
@@ -173,7 +174,7 @@ fill_default_server_options(ServerOption
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* Standard Options */
 	if (options->protocol == SSH_PROTO_UNKNOWN)
@@ -210,7 +211,7 @@ fill_default_server_options(ServerOption
 	if (options->key_regeneration_time == -1)
 		options->key_regeneration_time = 3600;
 	if (options->permit_root_login == PERMIT_NOT_SET)
-		options->permit_root_login = PERMIT_YES;
+		options->permit_root_login = PERMIT_NO;
 	if (options->ignore_rhosts == -1)
 		options->ignore_rhosts = 1;
 	if (options->ignore_user_known_hosts == -1)
@@ -220,7 +221,7 @@ fill_default_server_options(ServerOption
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -262,7 +263,11 @@ fill_default_server_options(ServerOption
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
@@ -368,7 +373,7 @@ fill_default_server_options(ServerOption
 		options->fwd_opts.streamlocal_bind_unlink = 0;
 	/* Turn privilege separation on by default */
 	if (use_privsep == -1)
-		use_privsep = PRIVSEP_NOSANDBOX;
+		use_privsep = PRIVSEP_ON;
 
 #ifndef HAVE_MMAP
 	if (use_privsep && options->compression == 1) {
