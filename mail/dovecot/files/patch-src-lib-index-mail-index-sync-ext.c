Index: src/lib-index/mail-index-sync-ext.c
===================================================================
RCS file: /home/cvs/dovecot/src/lib-index/mail-index-sync-ext.c,v
retrieving revision 1.11
retrieving revision 1.12
diff -u -r1.11 -r1.12
--- src/lib-index/mail-index-sync-ext.c	24 Sep 2005 10:12:03 -0000	1.11
+++ src/lib-index/mail-index-sync-ext.c	28 Oct 2005 14:10:13 -0000	1.12
@@ -332,6 +332,7 @@
 		unsigned i, count = array_count(&map->extensions);
 		ssize_t diff = (ssize_t)new_size - (ssize_t)old_size;
 
+		ext = array_idx_modifyable(&map->extensions, 0);
 		for (i = ext_id + 1; i < count; i++)
 			ext[i].hdr_offset += diff;
 	}
