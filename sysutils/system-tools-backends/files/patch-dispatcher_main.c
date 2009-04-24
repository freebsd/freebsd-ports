--- dispatcher/main.c.orig	2009-03-17 02:57:49.000000000 +0100
+++ dispatcher/main.c	2009-04-16 10:05:33.000000000 +0200
@@ -48,7 +48,7 @@ daemonize (void)
   setsid ();
 
   if ((pidfile_fd = open (LOCALSTATEDIR "/run/system-tools-backends.pid",
-                          O_CREAT | O_WRONLY,
+                          O_CREAT | O_WRONLY, 0600,
                           S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) != -1)
     {
       str = g_strdup_printf ("%d", getpid ());
