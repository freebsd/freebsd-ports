--- camel/camel-vee-folder.c.orig	Mon Jun 23 13:59:58 2003
+++ camel/camel-vee-folder.c	Tue Oct 21 20:04:10 2003
@@ -969,7 +969,7 @@
 				}
 				if ((vf->flags & CAMEL_STORE_FOLDER_PRIVATE) == 0) {
 					if (still) {
-						if (g_hash_table_lookup_extended(unmatched_uids, uid, (void **)&oldkey, (void **)&n)) {
+						if (g_hash_table_lookup_extended(unmatched_uids, uid, (void **)&oldkey, (void **)&n) && n > 0) {
 							if (n == 1) {
 								g_hash_table_remove(unmatched_uids, oldkey);
 								if (vee_folder_add_uid(folder_unmatched, source, oldkey+8, hash))
@@ -1290,7 +1290,7 @@
 					camel_folder_change_info_add_uid(folder_unmatched->changes, oldkey);
 			}
 		} else {
-			if (g_hash_table_lookup_extended(unmatched_uids, vuid, (void **)&oldkey, (void **)&n)) {
+			if (g_hash_table_lookup_extended(unmatched_uids, vuid, (void **)&oldkey, (void **)&n) && n > 0) {
 				g_hash_table_remove(unmatched_uids, oldkey);
 				g_free(oldkey);
 			}
