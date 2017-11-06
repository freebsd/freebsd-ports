--- libxcmd/paths.c.orig	2015-07-24 04:28:04 UTC
+++ libxcmd/paths.c
@@ -364,7 +364,7 @@ fs_table_initialise_mounts(
 			continue;
 		if (!realpath(stats[i].f_mntfromname, rmntfromname))
 			continue;
-		if (!realpath(stats[i].f_mntonname, rmnttomname)))
+		if (!realpath(stats[i].f_mntonname, rmntonname))
 			continue;
 
 		if (path &&
