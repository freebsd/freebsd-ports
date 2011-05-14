--- libgksu/libgksu.c.orig	2009-03-04 18:53:02.000000000 +0000
+++ libgksu/libgksu.c	2011-04-12 16:45:53.000000000 +0000
@@ -23,13 +23,15 @@
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
-#include <pty.h>
 #include <pwd.h>
+#include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/select.h>
 #include <errno.h>
+#include <termios.h>
+#include <libutil.h>
 
 #include <glibtop.h>
 #include <glibtop/procstate.h>
@@ -1089,8 +1091,8 @@
   gchar *xauth = g_new0 (gchar, 256);
 
   /* find out where the xauth binary is located */
-  if (g_file_test ("/usr/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
-    xauth_bin = "/usr/bin/xauth";
+  if (g_file_test ("/usr/local/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
+    xauth_bin = "/usr/local/bin/xauth";
   else if (g_file_test ("/usr/X11R6/bin/xauth", G_FILE_TEST_IS_EXECUTABLE))
     xauth_bin = "/usr/X11R6/bin/xauth";
   else
@@ -1976,7 +1978,7 @@
       gchar **cmd = g_malloc (sizeof(gchar*)*7);
 
       setsid();   // make us session leader
-      cmd[i] = g_strdup ("/bin/su"); i++;
+      cmd[i] = g_strdup ("/usr/bin/su"); i++;
       if (context->login_shell)
 	{
 	  cmd[i] = g_strdup ("-"); i++;
@@ -1998,7 +2000,7 @@
       if (execv (cmd[0], cmd) == -1)
 	{
 	  fprintf (stderr,
-		   "Unable to run /bin/su: %s",
+		   "Unable to run /usr/bin/su: %s",
 		   strerror(errno));
 	}
 
@@ -2190,8 +2192,6 @@
 	      write (fdpty, line, strlen(line));
 	      g_free (line);
 
-	      tcdrain (fdpty);
-
 	      bzero (buf, 256);
 	      read (fdpty, buf, 255);
 
@@ -2503,7 +2503,7 @@
   if (context->always_ask_password)
     {
        gint exit_status;
-       g_spawn_command_line_sync("/usr/bin/sudo -K", NULL, NULL, &exit_status, NULL);
+       g_spawn_command_line_sync("/usr/local/bin/sudo -K", NULL, NULL, &exit_status, NULL);
     }
 
 
@@ -2533,7 +2533,7 @@
   argcount = 0;
 
   /* sudo binary */
-  cmd[argcount] = g_strdup("/usr/bin/sudo");
+  cmd[argcount] = g_strdup("/usr/local/bin/sudo");
   argcount++;
 
   if (!context->keep_env)
