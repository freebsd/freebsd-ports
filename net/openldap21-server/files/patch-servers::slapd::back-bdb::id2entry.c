#
# ITS#2672: eternal loop in back-bdb/id2entry.c
#
--- servers/slapd/back-bdb/id2entry.c	2003/03/24 03:54:12	1.24.2.9
+++ servers/slapd/back-bdb/id2entry.c	2003/08/09 16:14:04	1.24.2.10
@@ -125,6 +125,8 @@
 	}
 
 	if ( rc == 0 ) {
+		int add_loop_cnt = 0;
+
 #ifdef BDB_HIER
 		bdb_fix_dn(be, id, *e);
 #endif
@@ -132,7 +134,6 @@
 				&bdb->bi_cache, *e, rw, locker, lock);
 		while ( ret == 1 || ret == -1 ) {
 			Entry *ee;
-			int add_loop_cnt = 0;
 			if ( (*e)->e_private != NULL ) {
 				free ((*e)->e_private);
 			}
