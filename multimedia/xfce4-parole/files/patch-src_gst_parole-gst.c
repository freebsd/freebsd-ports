--- src/gst/parole-gst.c.orig	2012-08-08 19:34:30.000000000 +0000
+++ src/gst/parole-gst.c	2012-08-10 22:16:18.000000000 +0000
@@ -84,7 +84,7 @@
 
     GstBus       *bus;
     
-    GMutex       lock;
+    GMutex       *lock;
     GstState      state;
     GstState      target;
     ParoleState media_state;
@@ -166,7 +166,7 @@
     if ( gst->priv->device )
 	g_free (gst->priv->device);
     
-    g_mutex_clear (&gst->priv->lock);
+    g_mutex_free (gst->priv->lock);
 
     G_OBJECT_CLASS (parole_gst_parent_class)->finalize (object);
 }
@@ -1515,10 +1515,10 @@
 		  "has-video", &playing_video,
 		  NULL);
     
-    g_mutex_lock (&gst->priv->lock);
+    g_mutex_lock (gst->priv->lock);
     gst->priv->target = GST_STATE_NULL;
     parole_stream_init_properties (gst->priv->stream);
-    g_mutex_unlock (&gst->priv->lock);
+    g_mutex_unlock (gst->priv->lock);
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     
@@ -1844,7 +1844,7 @@
     gst->priv->target = GST_STATE_VOID_PENDING;
     gst->priv->media_state = PAROLE_STATE_STOPPED;
     gst->priv->aspect_ratio = PAROLE_ASPECT_RATIO_NONE;
-    g_mutex_init (&gst->priv->lock);
+    gst->priv->lock = g_mutex_new ();
     gst->priv->stream = parole_stream_new ();
     gst->priv->tick_id = 0;
     gst->priv->hidecursor_timer = g_timer_new ();
@@ -1921,7 +1921,7 @@
 
 void parole_gst_play_uri (ParoleGst *gst, const gchar *uri, const gchar *subtitles)
 {
-    g_mutex_lock (&gst->priv->lock);
+    g_mutex_lock (gst->priv->lock);
     
     gst->priv->target = GST_STATE_PLAYING;
     parole_stream_init_properties (gst->priv->stream);
@@ -1931,7 +1931,7 @@
 		  "subtitles", subtitles,
 		  NULL);
 
-    g_mutex_unlock (&gst->priv->lock);
+    g_mutex_unlock (gst->priv->lock);
     
     if ( gst->priv->state_change_id == 0 )
 	gst->priv->state_change_id = g_timeout_add_seconds (20, 
@@ -1972,11 +1972,11 @@
 
 void parole_gst_pause (ParoleGst *gst)
 {
-    g_mutex_lock (&gst->priv->lock);
+    g_mutex_lock (gst->priv->lock);
     
     gst->priv->target = GST_STATE_PAUSED;
     
-    g_mutex_unlock (&gst->priv->lock);
+    g_mutex_unlock (gst->priv->lock);
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     parole_gst_change_state (gst, GST_STATE_PAUSED);
@@ -1984,11 +1984,11 @@
 
 void parole_gst_resume (ParoleGst *gst)
 {
-    g_mutex_lock (&gst->priv->lock);
+    g_mutex_lock (gst->priv->lock);
     
     gst->priv->target = GST_STATE_PLAYING;
     
-    g_mutex_unlock (&gst->priv->lock);
+    g_mutex_unlock (gst->priv->lock);
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     parole_gst_change_state (gst, GST_STATE_PLAYING);
@@ -2008,12 +2008,12 @@
 
 void parole_gst_stop (ParoleGst *gst)
 {
-    g_mutex_lock (&gst->priv->lock);
+    g_mutex_lock (gst->priv->lock);
     
     parole_stream_init_properties (gst->priv->stream);
     gst->priv->target = GST_STATE_NULL;
 		  
-    g_mutex_unlock (&gst->priv->lock);
+    g_mutex_unlock (gst->priv->lock);
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     
