--- libgksu/gksu-context.c.orig	Mon May  1 01:08:30 2006
+++ libgksu/gksu-context.c	Mon May 22 14:06:23 2006
@@ -23,9 +23,14 @@
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
-#include <pty.h>
-#include <pwd.h>
+
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#include <signal.h>
+
+#include <pwd.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/select.h>
@@ -455,6 +460,7 @@
   gchar *tmp = NULL;
   gchar **tmpv = NULL;
   gchar *display = NULL;
+  size_t r;
 
   /* avoid problems with "network" DISPLAY's */
   display = g_strdup (getenv ("DISPLAY"));
@@ -484,6 +490,7 @@
 			 "head -1 | awk '{ print $3 }'",
 			 xauth_bin,
 			 context->display);
+
   if ((xauth_output = popen (tmp, "r")) == NULL)
     {
       fprintf (stderr,
@@ -491,8 +498,8 @@
 	       strerror(errno));
       return 1;
     }
-  fread (xauth, sizeof(char), 256, xauth_output);
-  xauth[strlen(xauth) - 1] = '\0';
+  r = fread (xauth, sizeof(char), 256, xauth_output);
+  xauth[r] = '\0';
   pclose (xauth_output);
   g_free (tmp);
 
@@ -650,7 +657,7 @@
     {
       gchar **cmd = g_malloc (sizeof(gchar*)*7);
 
-      cmd[i] = g_strdup ("/bin/su"); i++;
+      cmd[i] = g_strdup ("/usr/bin/su"); i++;
       if (context->login_shell)
 	{
 	  cmd[i] = g_strdup ("-"); i++;
@@ -671,7 +678,7 @@
       if (execv (cmd[0], cmd) == -1)
 	{
 	  fprintf (stderr,
-		   _("Unable to run /bin/su: %s"),
+		   _("Unable to run /usr/bin/su: %s"),
 		   strerror(errno));
 
 	  for (i = 0 ; cmd[i] != NULL ; i++)
@@ -808,7 +815,7 @@
     {
       gchar **cmd = g_malloc (sizeof(gchar*)*7);
 
-      cmd[i] = g_strdup ("/bin/su"); i++;
+      cmd[i] = g_strdup ("/usr/bin/su"); i++;
       if (context->login_shell)
 	{
 	  cmd[i] = g_strdup ("-"); i++;
@@ -830,7 +837,7 @@
       if (execv (cmd[0], cmd) == -1)
 	{
 	  fprintf (stderr,
-		   _("Unable to run /bin/su: %s"),
+		   _("Unable to run /usr/bin/su: %s"),
 		   strerror(errno));
 	}
 
@@ -1097,7 +1104,7 @@
   argcount = 0;
 
   /* sudo binary */
-  cmd[argcount] = g_strdup("/usr/bin/sudo");
+  cmd[argcount] = g_strdup("/usr/local/bin/sudo");
   argcount++;
 
   /* Make sudo read from STDIN */
@@ -1276,7 +1283,7 @@
   argcount = 0;
 
   /* sudo binary */
-  cmd[argcount] = g_strdup("/usr/bin/sudo");
+  cmd[argcount] = g_strdup("/usr/local/bin/sudo");
   argcount++;
 
   if (!context->keep_env)
