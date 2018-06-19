r99048 | des | 2002-06-29 05:51:56 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/myproposal.h
   M /head/crypto/openssh/readconf.c
   M /head/crypto/openssh/servconf.c

Apply FreeBSD's configuration defaults.

--- servconf.c.orig	2018-06-19 09:26:26 UTC
+++ servconf.c
@@ -63,6 +63,7 @@
 #include "auth.h"
 #include "myproposal.h"
 #include "digest.h"
+#include "version.h"
 
 static void add_listen_addr(ServerOptions *, const char *,
     const char *, int);
@@ -240,7 +241,11 @@ fill_default_server_options(ServerOption
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
+#ifdef USE_PAM
+		options->use_pam = 1;
+#else
 		options->use_pam = 0;
+#endif
 
 	/* Standard Options */
 	if (options->num_host_key_files == 0) {
@@ -280,7 +285,7 @@ fill_default_server_options(ServerOption
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -320,7 +325,11 @@ fill_default_server_options(ServerOption
 	if (options->gss_strict_acceptor == -1)
 		options->gss_strict_acceptor = 1;
 	if (options->password_authentication == -1)
+#ifdef USE_PAM
+		options->password_authentication = 0;
+#else
 		options->password_authentication = 1;
+#endif
 	if (options->kbd_interactive_authentication == -1)
 		options->kbd_interactive_authentication = 0;
 	if (options->challenge_response_authentication == -1)
