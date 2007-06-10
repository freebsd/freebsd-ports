--- libztxt/ztxt_disect.c.orig	Sun Jun  3 13:31:46 2007
+++ libztxt/ztxt_disect.c	Sun Jun  3 13:32:42 2007
@@ -152,8 +152,8 @@
   zstream.zalloc = Z_NULL;
   zstream.zfree = Z_NULL;
   zstream.opaque = Z_NULL;
-  zstream.next_in = &db->output[ntohl(db->dbRecordEntries[1].localChunkID)];
-  zstream.next_out = db->input;
+  zstream.next_in = (Bytef *)&db->output[ntohl(db->dbRecordEntries[1].localChunkID)];
+  zstream.next_out = (Bytef *)db->input;
   zstream.avail_in = data_size;
   zstream.avail_out = db->input_size + 1;
 
