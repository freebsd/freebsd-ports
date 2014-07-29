--- src/areas.c.orig	Sun Oct 24 20:16:14 1999
+++ src/areas.c	Sun Oct 24 20:19:15 1999
@@ -305,9 +305,6 @@
 
   /* make a backup copy of areas_file */
   strcpy(new_path,areas_file);
-  if(strchr(new_path,'.'))
-    strcpy(strrchr(new_path,'.'),".bak");
-  else
     strcat(new_path,".bak");
   if(rename(areas_file,new_path))
     l_printf("Warning: unable to move %s to %s",areas_file,new_path);
