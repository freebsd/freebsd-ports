--- src/emoticons.c.orig	Thu Dec 16 22:50:31 2004
+++ src/emoticons.c	Thu Dec 16 22:51:27 2004
@@ -347,9 +347,9 @@
 	gchar *caption;	/* Should be enough... */
 
 	if (kf_preferences_get_int ("chatShowStamps")) {
+		gchar *sstamp;
 		struct tm *stime;
 		stime = localtime ((time_t *) &stamp);
-		gchar *sstamp;
 
 		gtk_text_buffer_get_end_iter (buffer, &iter);
 		if (stamp < time (NULL) - 3600 * 24) {
