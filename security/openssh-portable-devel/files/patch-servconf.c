--- servconf.c.orig	2015-03-22 23:58:50.869706000 -0500
+++ servconf.c	2015-03-22 23:59:46.645390000 -0500
@@ -81,6 +81,7 @@
 #include "auth.h"
 #include "myproposal.h"
 #include "digest.h"
+#include "version.h"
 
 static void add_listen_addr(ServerOptions *, char *, int);
 static void add_one_listen_addr(ServerOptions *, char *, int);
@@ -216,7 +217,7 @@ fill_default_server_options(ServerOption
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* X.509 Standard Options */
 #ifdef OPENSSL_FIPS
@@ -287,7 +288,7 @@ fill_default_server_options(ServerOption
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -333,7 +334,11 @@ fill_default_server_options(ServerOption
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
@@ -396,7 +401,7 @@ fill_default_server_options(ServerOption
 		options->fingerprint_hash = SSH_FP_HASH_DEFAULT;
 	/* Turn privilege separation on by default */
 	if (use_privsep == -1)
-		use_privsep = PRIVSEP_NOSANDBOX;
+		use_privsep = PRIVSEP_ON;
 
 #define CLEAR_ON_NONE(v) \
 	do { \
