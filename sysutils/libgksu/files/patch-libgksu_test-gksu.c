--- libgksu/test-gksu.c.orig	Thu Sep 30 20:40:04 2004
+++ libgksu/test-gksu.c	Thu Sep 30 17:39:36 2004
@@ -34,7 +34,7 @@
   context = gksu_context_new ();
 
   gksu_context_set_debug (context, TRUE);
-  gksu_context_set_command (context, "/usr/bin/X11/xterm");
+  gksu_context_set_command (context, "/usr/X11R6/bin/xterm");
 
   password = getpass ("Type the root password: ");
   gksu_context_set_password (context, password);
