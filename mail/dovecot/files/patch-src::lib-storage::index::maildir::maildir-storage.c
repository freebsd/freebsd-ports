--- src/lib-storage/index/maildir/maildir-storage.c.orig	Wed Feb 26 05:58:45 2003
+++ src/lib-storage/index/maildir/maildir-storage.c	Sun Apr 20 02:33:17 2003
@@ -434,7 +434,7 @@
 		i_assert(oldnamelen <= strlen(list->name));
 
 		t_push();
-		new_listname = t_strconcat(newname, ".",
+		new_listname = t_strconcat(newname,
 					   list->name + oldnamelen, NULL);
 		oldpath = maildir_get_path(storage, list->name);
 		newpath = maildir_get_path(storage, new_listname);
