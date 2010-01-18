--- src/programs/pkexec.c.orig	2010-01-18 02:52:40.000000000 -0500
+++ src/programs/pkexec.c	2010-01-18 03:06:57.000000000 -0500
@@ -438,7 +438,7 @@ main (int argc, char *argv[])
       goto out;
     }
 
-  original_cwd = g_strdup (get_current_dir_name ());
+  original_cwd = g_strdup (getcwd (NULL, 0));
   if (original_cwd == NULL)
     {
       g_printerr ("Error getting cwd.\n");
