--- servconf.c.orig	2015-08-17 20:37:29.913831000 UTC
+++ servconf.c	2015-08-17 20:37:29.950132000 -0700
@@ -57,6 +57,7 @@
 #include "auth.h"
 #include "myproposal.h"
 #include "digest.h"
+#include "version.h"
 
 static void add_listen_addr(ServerOptions *, char *, int);
 static void add_one_listen_addr(ServerOptions *, char *, int);
@@ -193,7 +194,7 @@ fill_default_server_options(ServerOption
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
-		options->use_pam = 0;
+		options->use_pam = 1;
 
 	/* Standard Options */
 	if (options->protocol == SSH_PROTO_UNKNOWN)
@@ -242,7 +243,7 @@ fill_default_server_options(ServerOption
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -288,7 +289,11 @@ fill_default_server_options(ServerOption
 	if (options->gss_strict_acceptor == -1)
 		options->gss_strict_acceptor = 0;
 	if (options->password_authentication == -1)
+#ifdef USE_PAM
+		options->password_authentication = 0;
+#else
 		options->password_authentication = 1;
+#endif
 	if (options->kbd_interactive_authentication == -1)
 		options->kbd_interactive_authentication = 0;
 	if (options->challenge_response_authentication == -1)
