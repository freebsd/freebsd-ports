--- client.c.orig	Thu May  8 12:34:44 2003
+++ client.c	Mon Aug 18 10:30:05 2003
@@ -400,7 +400,7 @@
 
   if( *config_file == '\0' ){
     if (env)
-      strncpy ( rcfile, env, sizeof(rcsfile) - strlen(youbinrc) - 1);
+      strncpy ( rcfile, env, sizeof(rcfile) - strlen(youbinrc) - 1);
     else if ((pwent = (struct passwd *) getpwuid (getuid ()))
 	     && pwent->pw_dir)
       strcpy ( rcfile, pwent->pw_dir);
