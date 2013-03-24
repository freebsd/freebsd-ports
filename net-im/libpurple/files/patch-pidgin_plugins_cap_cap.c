--- pidgin/plugins/cap/cap.c.orig	2013-03-24 20:34:29.882262000 +0000
+++ pidgin/plugins/cap/cap.c	2013-03-24 20:34:39.576121000 +0000
@@ -43,7 +43,7 @@ static double generate_prediction_for(Pu
 	int threshold = purple_prefs_get_int("/plugins/gtk/cap/threshold");
 	int min_minute = (current_minute - threshold) % 1440;
 	int max_minute = (current_minute + threshold) % 1440;
-	char *sql, sta_id = NULL;
+	char *sql, *sta_id = NULL;
 	sqlite3_stmt *stmt = NULL;
 	const char *tail = NULL;
 	int rc;
