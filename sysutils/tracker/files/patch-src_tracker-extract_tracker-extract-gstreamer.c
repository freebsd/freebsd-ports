--- src/tracker-extract/tracker-extract-gstreamer.c.orig
+++ src/tracker-extract/tracker-extract-gstreamer.c
@@ -1647,7 +1647,9 @@ tracker_extract_gstreamer (const gchar          *uri,
 		                  graph);
 
 #ifdef HAVE_LIBMEDIAART
-		if (extractor->media_art_type != MEDIA_ART_NONE) {
+		if (extractor->media_art_type != MEDIA_ART_NONE &&
+		    (extractor->media_art_artist != NULL ||
+		     extractor->media_art_title != NULL)) {
 			GError *error = NULL;
 			gboolean success = TRUE;
 
