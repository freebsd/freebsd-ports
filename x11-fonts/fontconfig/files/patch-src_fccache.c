--- src/fccache.c	2003/03/05 05:51:27	1.17
+++ src/fccache.c	2003/03/12 22:15:39	1.18
@@ -309,14 +309,14 @@
  * Verify the saved timestamp for a file
  */
 FcBool
-FcGlobalCacheCheckTime (FcGlobalCacheInfo *info)
+FcGlobalCacheCheckTime (const FcChar8 *file, FcGlobalCacheInfo *info)
 {
     struct stat	    statb;
 
-    if (stat ((char *) info->file, &statb) < 0)
+    if (stat ((char *) file, &statb) < 0)
     {
 	if (FcDebug () & FC_DBG_CACHE)
-	    printf (" file missing\n");
+	    printf (" file %s missing\n", file);
 	return FcFalse;
     }
     if (statb.st_mtime != info->time)
@@ -549,7 +549,7 @@
      * See if the timestamp recorded in the global cache
      * matches the directory time, if not, return False
      */
-    if (!FcGlobalCacheCheckTime (&d->info))
+    if (!FcGlobalCacheCheckTime (d->info.file, &d->info))
     {
 	if (FcDebug () & FC_DBG_CACHE)
 	    printf ("\tdir cache entry time mismatch\n");
@@ -633,7 +633,7 @@
 	}
     }
     if (count)
-	*count = max;
+	*count = max + 1;
     return match;
 }
     
