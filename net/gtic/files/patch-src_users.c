--- src/users.c.orig	Sun Oct 24 20:19:46 1999
+++ src/users.c	Sun Oct 24 20:20:10 1999
@@ -125,9 +125,6 @@
   
   /* make a backup copy of users_file */
   strcpy(new_path,users_file);
-  if(strchr(new_path,'.'))
-    strcpy(strrchr(new_path,'.'),".bak");
-  else
     strcat(new_path,".bak");
   if(rename(users_file,new_path))
     l_printf("Warning: unable to move %s to %s",users_file,new_path);
