--- src/filesystem/e2_fs.c.orig	2009-03-22 12:08:27.000000000 +0100
+++ src/filesystem/e2_fs.c	2009-03-22 12:08:54.000000000 +0100
@@ -1046,7 +1046,7 @@
 	{
 //		if (errno == EINTR)
 //			goto retry;
-		else if (errno == ENOENT && descend && e2_utils_get_parent_path (localpath, TRUE))
+		if (errno == ENOENT && descend && e2_utils_get_parent_path (localpath, TRUE))
 			goto retry;
 		g_free (localpath);
 		return FALSE;
