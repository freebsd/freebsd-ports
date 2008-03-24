--- dispatcher/main.c.orig	2007-10-29 20:36:16.890317344 -0400
+++ dispatcher/main.c	2007-10-29 20:37:02.584773483 -0400
@@ -47,7 +47,7 @@
 
   setsid ();
 
-  if ((pidfile_fd = open (LOCALSTATEDIR "/run/system-tools-backends.pid", O_CREAT | O_WRONLY)) != -1)
+  if ((pidfile_fd = open (LOCALSTATEDIR "/run/system-tools-backends.pid", O_CREAT | O_WRONLY, 0600)) != -1)
     {
       str = g_strdup_printf ("%d", getpid ());
       write (pidfile_fd, str, strlen (str));
