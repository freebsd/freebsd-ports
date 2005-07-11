
$FreeBSD$

--- src/cddb.c.orig
+++ src/cddb.c
@@ -117,13 +117,14 @@
   }
   for(i = 0; i < i_tracks; i++) {
     cddb_track_t *t = cddb_track_new(); 
-    t->frame_offset = cdio_get_track_lba(p_cdio, i+i_first_track);
+    cddb_track_set_frame_offset(t,
+	cdio_get_track_lba(p_cdio, i+i_first_track));
     cddb_disc_add_track(*pp_cddb_disc, t);
   }
   
-  (*pp_cddb_disc)->length = 
+  cddb_disc_set_length(*pp_cddb_disc,
     cdio_get_track_lba(p_cdio, CDIO_CDROM_LEADOUT_TRACK) 
-    / CDIO_CD_FRAMES_PER_SEC;
+    / CDIO_CD_FRAMES_PER_SEC);
   
   if (!cddb_disc_calc_discid(*pp_cddb_disc)) {
     errmsg("libcddb calc discid failed.");
