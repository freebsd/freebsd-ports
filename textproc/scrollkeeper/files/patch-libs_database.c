--- libs/database.c.orig	Sat May 25 23:17:10 2002
+++ libs/database.c	Sat May 25 23:18:01 2002
@@ -73,7 +73,8 @@
     
     /* create locale directories and symlinks */
     
-    dir = opendir(data_dir);
+    if ((dir = opendir(data_dir)) == NULL)
+	return;
     
     while((dir_ent = readdir(dir)) != NULL)
     {
