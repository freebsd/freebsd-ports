--- prefs.c.orig	Thu Apr 19 18:38:27 2001
+++ prefs.c	Thu Apr 19 18:39:02 2001
@@ -14,7 +14,7 @@
 	start_map = malloc (30);
 	value = malloc (100);
 	option = malloc (30);
-	sprintf (prefs_path,"%s/%s",getenv("HOME"),GEO_PREFS_FILE);
+	sprintf (prefs_path,"%s",GEO_PREFS_FILE);
 	strcpy (traceroute_path,TRACE_PATH_DEF);
 	strcpy (maps_dir_path,MAPS_DIR_DEF);
 	strcpy (start_map,START_MAP_DEF);
