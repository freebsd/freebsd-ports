
$FreeBSD$

--- libbanshee/banshee-player-pipeline.c.orig
+++ libbanshee/banshee-player-pipeline.c
@@ -236,6 +236,7 @@
 
 static void bp_volume_changed_callback (GstElement *playbin, GParamSpec *spec, BansheePlayer *player)
 {
+    return;
     g_return_if_fail (IS_BANSHEE_PLAYER (player));
     g_return_if_fail (GST_IS_ELEMENT (playbin));
 
