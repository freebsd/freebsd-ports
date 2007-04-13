--- dispatcher/dispatcher.c.orig	Thu Apr 12 23:55:38 2007
+++ dispatcher/dispatcher.c	Thu Apr 12 23:57:40 2007
@@ -203,7 +203,7 @@ daemonize (void)
 
       setsid ();
 
-      if ((pidfile_fd = open (LOCALSTATEDIR "/run/system-tools-backends.pid", O_CREAT | O_WRONLY)) != -1)
+      if ((pidfile_fd = open (LOCALSTATEDIR "/run/system-tools-backends.pid", O_CREAT | O_WRONLY, 0600)) != -1)
 	{
 	  str = g_strdup_printf ("%d", getpid ());
 	  write (pidfile_fd, str, strlen (str));
