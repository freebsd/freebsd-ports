--- ./src/parole-player.c.orig	2013-03-07 00:14:28.000000000 +0000
+++ ./src/parole-player.c	2013-04-28 16:08:15.000000000 +0000
@@ -1650,6 +1650,7 @@
 	seek =  parole_gst_get_stream_position (PAROLE_GST (player->priv->gst) )
 			-
 			seek;
+	if ( seek < 0 ) { seek = 0; }
 	parole_gst_seek (PAROLE_GST (player->priv->gst), seek);
 	parole_player_change_range_value (player, seek);
 }
@@ -2241,7 +2242,7 @@
 {
     gdouble value;
     value = gtk_scale_button_get_value (GTK_SCALE_BUTTON (player->priv->volume));
-    gtk_scale_button_set_value (GTK_SCALE_BUTTON (player->priv->volume), value + 0.1);
+    gtk_scale_button_set_value (GTK_SCALE_BUTTON (player->priv->volume), value + 0.05);
 }
 
 void
@@ -2249,7 +2250,7 @@
 {
     gdouble value;
     value = gtk_scale_button_get_value (GTK_SCALE_BUTTON (player->priv->volume));
-    gtk_scale_button_set_value (GTK_SCALE_BUTTON (player->priv->volume), value - 0.1);
+    gtk_scale_button_set_value (GTK_SCALE_BUTTON (player->priv->volume), value - 0.05);
 }
 
 void parole_player_volume_mute (GtkWidget *widget, ParolePlayer *player)
