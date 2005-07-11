
$FreeBSD$

--- src/cdda-player.c.orig
+++ src/cdda-player.c
@@ -381,12 +381,6 @@
   return b_ok;
 }
 
-#define add_cddb_disc_info(format_str, field)  \
-  if (p_cddb_disc->field && !strlen(field))  { \
-    snprintf(field, sizeof(field), format_str, p_cddb_disc->field); \
-    b_cdtext_ ## field = false;                                     \
-  }
-
 static void 
 get_cddb_disc_info(CdIo_t *p_cdio) 
 {
@@ -394,10 +388,12 @@
   b_db = init_cddb(p_cdio, &p_conn, &p_cddb_disc, xperror, i_first_track, 
 		   i_tracks, &i_cddb_matches);
   if (b_db) {
-    add_cddb_disc_info("%s",  artist);
-    add_cddb_disc_info("%s",  title);
-    add_cddb_disc_info("%s",  genre);
-    add_cddb_disc_info("%4d", year);
+       int i_year;
+       i_year = atoi(year);
+       cddb_disc_set_artist(p_cddb_disc, artist);
+       cddb_disc_set_title(p_cddb_disc, title);
+       cddb_disc_set_genre(p_cddb_disc, genre);
+       cddb_disc_set_year(p_cddb_disc, i_year);
   }
 #endif
   return;
@@ -687,11 +683,6 @@
 
 }
 
-#define add_cddb_track_info(format_str, field) \
-  if (t->field) \
-    snprintf(cd_info[i_track].field, sizeof(cd_info[i_track].field)-1, \
-	     format_str, t->field);
-
 static void
 get_cddb_track_info(track_t i_track)
 {
@@ -699,8 +690,8 @@
   cddb_track_t *t = cddb_disc_get_track(p_cddb_disc, 
 					i_track - i_first_track);
   if (t) {
-    add_cddb_track_info("%s", title);
-    add_cddb_track_info("%s", artist);
+      cddb_track_set_title(t, title);
+      cddb_track_set_artist(t, artist);
   }
   
 #else
