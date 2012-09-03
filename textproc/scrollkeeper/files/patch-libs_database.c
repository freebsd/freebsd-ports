--- libs/database.c.orig	2002-06-02 06:03:10.000000000 +0000
+++ libs/database.c	2012-09-03 22:39:28.000000000 +0000
@@ -131,7 +131,8 @@
     
     /* create locale directories and symlinks */
     
-    dir = opendir(data_dir);
+    if ((dir = opendir(data_dir)) == NULL)
+	return 1;
     
     while((dir_ent = readdir(dir)) != NULL)
     {
