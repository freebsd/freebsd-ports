--- libreiserfs/journal.c	Thu Dec 12 13:32:35 2002
+++ libreiserfs/journal.c.new	Thu May 13 00:01:43 2004
@@ -482,7 +482,7 @@
 blk_t reiserfs_journal_boundary_transactions(reiserfs_journal_t *journal,
     reiserfs_journal_trans_t *oldest, reiserfs_journal_trans_t *newest)
 {
-    reiserfs_gauge_t *gauge;
+    reiserfs_gauge_t *gauge = NULL;
     struct reiserfs_replay_desc desc;
 	
     desc.oldest_id = 0xffffffff; desc.newest_id = 0x0;
