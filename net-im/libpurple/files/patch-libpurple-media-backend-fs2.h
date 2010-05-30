--- libpurple/media/backend-fs2.h.orig	2010-05-22 16:51:01.677902000 +0800
+++ libpurple/media/backend-fs2.h	2010-05-23 16:07:07.000000000 +0800
@@ -59,6 +59,7 @@
  * Temporary function in order to be able to test while
  * integrating with PurpleMedia
  */
+#ifdef USE_GSTREAMER
 #include <gst/gst.h>
 GstElement *purple_media_backend_fs2_get_src(
 		PurpleMediaBackendFs2 *self,
@@ -70,6 +71,7 @@
 		const gchar *sess_id, double level);
 void purple_media_backend_fs2_set_output_volume(PurpleMediaBackendFs2 *self,
 		const gchar *sess_id, const gchar *who, double level);
+#endif
 /* end tmp */
 
 G_END_DECLS
