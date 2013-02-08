--- ./src/network/network-locations.h.orig	2010-05-24 21:09:57.000000000 +0400
+++ ./src/network/network-locations.h	2012-12-14 16:47:54.000000000 +0400
@@ -62,7 +62,7 @@
 							      const gchar         *name);
 gboolean               gst_network_locations_save_current    (GstNetworkLocations *locations,
 							      const gchar         *name);
-void                   gst_network_locations_delete_location (GstNetworkLocations *locations,
+gboolean               gst_network_locations_delete_location (GstNetworkLocations *locations,
 							      const gchar         *name);
 
 G_END_DECLS
