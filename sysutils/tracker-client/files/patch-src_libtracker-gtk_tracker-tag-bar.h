--- src/libtracker-gtk/tracker-tag-bar.h.orig	2007-07-17 04:35:33.000000000 +0400
+++ src/libtracker-gtk/tracker-tag-bar.h	2007-08-25 00:53:14.000000000 +0400
@@ -59,6 +59,8 @@
 				    const gchar 		*uri
 				   );
 
+GType tracker_tag_bar_get_type(void);
+
 G_END_DECLS
 
 #endif /* TRACKER_TAG_BAR_H */
