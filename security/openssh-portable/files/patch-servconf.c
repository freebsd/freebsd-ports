r99048 | des | 2002-06-29 05:51:56 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/myproposal.h
   M /head/crypto/openssh/readconf.c
   M /head/crypto/openssh/servconf.c

Apply FreeBSD's configuration defaults.

--- servconf.c.orig	2018-06-27 17:18:19.513676000 -0700
+++ servconf.c	2018-06-27 17:19:38.133882000 -0700
@@ -41,6 +41,7 @@
 #include <util.h>
 #endif
 
+#include "version.h"
 #include "openbsd-compat/sys-queue.h"
 #include "xmalloc.h"
 #include "ssh.h"
@@ -251,7 +252,11 @@ fill_default_server_options(ServerOptions *options)
 
 	/* Portable-specific options */
 	if (options->use_pam == -1)
+#ifdef USE_PAM
+		options->use_pam = 1;
+#else
 		options->use_pam = 0;
+#endif
 
 	/* Standard Options */
 	if (options->num_host_key_files == 0) {
@@ -291,7 +296,7 @@ fill_default_server_options(ServerOptions *options)
 	if (options->print_lastlog == -1)
 		options->print_lastlog = 1;
 	if (options->x11_forwarding == -1)
-		options->x11_forwarding = 0;
+		options->x11_forwarding = 1;
 	if (options->x11_display_offset == -1)
 		options->x11_display_offset = 10;
 	if (options->x11_use_localhost == -1)
@@ -331,7 +336,11 @@ fill_default_server_options(ServerOptions *options)
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
