diff -u -r1.14 -r1.15
--- src/fcdir.c	2003/03/05 05:51:27	1.14
+++ src/fcdir.c	2003/03/12 22:15:39	1.15
@@ -70,7 +70,7 @@
 		/*
 		 * Found a cache entry for the file
 		 */
-		if (FcGlobalCacheCheckTime (&cache_file->info))
+		if (FcGlobalCacheCheckTime (file, &cache_file->info))
 		{
 		    name = cache_file->name;
 		    need_scan = FcFalse;
@@ -89,7 +89,8 @@
 						       strlen ((const char *) file),
 						       FcFalse)))
 	    {
-		if (FcGlobalCacheCheckTime (&cache_dir->info))
+		if (FcGlobalCacheCheckTime (cache_dir->info.file, 
+					    &cache_dir->info))
 		{
 		    font = 0;
 		    need_scan = FcFalse;
@@ -199,6 +200,9 @@
     strcat ((char *) file, "/");
     base = file + strlen ((char *) file);
     
+    if (FcDebug () & FC_DBG_SCAN)
+	printf ("\tScanning dir %s\n", dir);
+	
     d = opendir ((char *) dir);
     
     if (!d)
