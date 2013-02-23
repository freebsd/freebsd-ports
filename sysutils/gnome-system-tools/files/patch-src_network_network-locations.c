--- ./src/network/network-locations.c.orig	2010-05-24 21:09:57.000000000 +0400
+++ ./src/network/network-locations.c	2012-12-14 16:44:29.000000000 +0400
@@ -1131,7 +1131,7 @@
   return result;
 }
 
-void
+gboolean
 gst_network_locations_delete_location (GstNetworkLocations *locations,
 				       const gchar         *name)
 {
