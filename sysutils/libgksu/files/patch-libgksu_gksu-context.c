--- libgksu/gksu-context.c.orig	Sun Oct 17 21:43:32 2004
+++ libgksu/gksu-context.c	Fri Nov  5 01:01:45 2004
@@ -23,9 +23,13 @@
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
+
+#include <pwd.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/select.h>
@@ -419,6 +423,7 @@
   gchar *tmp = NULL;
   gchar **tmpv = NULL;
   gchar *display = NULL;
+  size_t r;
 
   /* avoid problems with "network" DISPLAY's */
   display = g_strdup (getenv ("DISPLAY"));
@@ -434,6 +439,7 @@
 			 "grep 'MIT-MAGIC-COOKIE-1' | "
 			 "cut -d ' ' -f 5",
 			 context->display);
+
   if ((xauth_output = popen (tmp, "r")) == NULL)
     {
       fprintf (stderr,
@@ -441,8 +447,8 @@
 	       strerror(errno));
       return 1;
     }
-  fread (xauth, sizeof(char), 256, xauth_output);
-  xauth[strlen(xauth) - 1] = '\0';
+  r = fread (xauth, sizeof(char), 256, xauth_output);
+  xauth[r] = '\0';
   pclose (xauth_output);
   g_free (tmp);
 
@@ -637,7 +643,7 @@
     {
       gchar **cmd = g_malloc (sizeof(gchar*)*7);
 
-      cmd[i] = g_strdup ("/bin/su"); i++;
+      cmd[i] = g_strdup ("/usr/bin/su"); i++;
       if (context->login_shell)
 	{
 	  cmd[i] = g_strdup ("-"); i++;
@@ -659,7 +665,7 @@
       if (execv (cmd[0], cmd) == -1)
 	{
 	  fprintf (stderr, 
-		   _("Unable to run /bin/su: %s"),
+		   _("Unable to run /usr/bin/su: %s"),
 		   strerror(errno));
 	}
 
