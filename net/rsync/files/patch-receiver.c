#
# Fix an off-by-one error in the handling of --max-delete=N
# http://lists.samba.org/archive/rsync/2004-October/010853.html
#
--- receiver.c.orig	Tue Sep 21 11:24:06 2004
+++ receiver.c	Wed Oct 20 08:12:19 2004
@@ -116,7 +116,7 @@
 			rprintf(FINFO, "deleting in %s\n", safe_fname(fbuf));
 
 		for (i = local_file_list->count-1; i >= 0; i--) {
-			if (max_delete && deletion_count > max_delete)
+			if (max_delete && deletion_count >= max_delete)
 				break;
 			if (!local_file_list->files[i]->basename)
 				continue;
