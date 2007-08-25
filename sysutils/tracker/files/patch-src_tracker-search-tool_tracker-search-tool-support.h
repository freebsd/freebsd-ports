--- src/tracker-search-tool/tracker-search-tool-support.h.orig	2007-07-21 20:55:20.000000000 +0400
+++ src/tracker-search-tool/tracker-search-tool-support.h	2007-08-24 22:31:05.000000000 +0400
@@ -143,6 +143,15 @@
 tracker_search_get_stored_window_geometry (gint * width,
                                         gint * height);
 
+void
+tracker_set_stored_separator_position (int pos);
+
+char *
+tracker_string_replace (const char *haystack, char *needle, char *replacement);
+
+int
+tracker_get_stored_separator_position ();
+
 #ifdef __cplusplus
 }
 #endif
