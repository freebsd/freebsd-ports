--- src/test-vt-monitor.c.orig	2007-08-17 13:08:55.000000000 -0400
+++ src/test-vt-monitor.c	2007-11-08 15:11:37.000000000 -0500
@@ -31,6 +31,7 @@
 #include <pwd.h>
 #include <string.h>
 #include <errno.h>
+#include <signal.h>
 
 #include <locale.h>
 
@@ -55,12 +56,22 @@ main (int argc, char **argv)
         GError           *error;
         guint             num;
         gboolean          res;
+	struct sigaction  sa;
 
         if (! g_thread_supported ()) {
                 g_thread_init (NULL);
         }
         g_type_init ();
 
+	sa.sa_handler = SIG_DFL;
+	sigemptyset (&sa.sa_mask);
+	sa.sa_flags = 0;
+
+	sigaction (SIGINT,  &sa, NULL);
+	sigaction (SIGTERM, &sa, NULL);
+	sigaction (SIGQUIT, &sa, NULL);
+	sigaction (SIGHUP,  &sa, NULL);
+
         if (! ck_is_root_user ()) {
                 g_warning ("Must be run as root");
                 exit (1);
