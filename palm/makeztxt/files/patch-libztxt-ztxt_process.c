--- libztxt/ztxt_process.c.orig	Tue Aug 12 15:05:21 2003
+++ libztxt/ztxt_process.c	Sun Jun  3 13:29:24 2007
@@ -321,8 +321,8 @@
         /* Method 1 allows for random access in the compressed data */
 
         /* Set buffer pointers */
-        zstream.next_in = buf;
-        zstream.next_out = zbuf;
+        zstream.next_in = (Bytef *)buf;
+        zstream.next_out = (Bytef *)zbuf;
         zstream.avail_in = RECORD_SIZE;
         zstream.avail_out = zbuf_size;
 
@@ -354,7 +354,7 @@
                     memcpy(buf, &(db->tmp[zpos]), RECORD_SIZE);
                     zpos += RECORD_SIZE;
                     bytesleft -= RECORD_SIZE;
-                    zstream.next_in = buf;
+                    zstream.next_in = (Bytef *)buf;
                     zstream.avail_in = RECORD_SIZE;
                     db->num_records++;
                     offsets[db->num_records] = zstream.total_out;
@@ -365,7 +365,7 @@
                   {
                     memcpy(buf, &(db->tmp[zpos]), bytesleft);
                     zpos += bytesleft;
-                    zstream.next_in = buf;
+                    zstream.next_in = (Bytef *)buf;
                     zstream.avail_in = bytesleft;
                     db->num_records++;
                     offsets[db->num_records] = zstream.total_out;
@@ -402,8 +402,8 @@
         /* Method 2 gives about 10% - 15% more compression */
 
         /* Set buffer pointers */
-        zstream.next_in = db->tmp;
-        zstream.next_out = zbuf;
+        zstream.next_in = (Bytef *)db->tmp;
+        zstream.next_out = (Bytef *)zbuf;
         zstream.avail_in = db->tmpsize;
         zstream.avail_out = zbuf_size;
 
