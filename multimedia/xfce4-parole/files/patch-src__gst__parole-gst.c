--- ./src/gst/parole-gst.c.orig	2013-01-07 10:15:53.000000000 +0000
+++ ./src/gst/parole-gst.c	2013-01-08 21:36:35.000000000 +0000
@@ -97,8 +97,12 @@
     GstElement   *video_sink;
 
     GstBus       *bus;
-    
+
+#if GLIB_CHECK_VERSION (2, 32, 0)    
     GMutex       lock;
+#else
+    GMutex       *lock;
+#endif
     GstState      state;
     GstState      target;
     ParoleState media_state;
@@ -184,8 +188,12 @@
     
     if ( gst->priv->device )
 	g_free (gst->priv->device);
-    
+   
+#if GLIB_CHECK_VERSION (2, 32, 0) 
     g_mutex_clear (&gst->priv->lock);
+#else
+    g_mutex_free (gst->priv->lock);
+#endif
 
     G_OBJECT_CLASS (parole_gst_parent_class)->finalize (object);
 }
@@ -1876,11 +1884,19 @@
     g_object_get (G_OBJECT (gst->priv->stream), 
 		  "has-video", &playing_video,
 		  NULL);
-    
+   
+#if GLIB_CHECK_VERSION (2, 32, 0) 
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     gst->priv->target = GST_STATE_NULL;
     parole_stream_init_properties (gst->priv->stream);
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_unlock (&gst->priv->lock);
+#else
+    g_mutex_unlock (gst->priv->lock);
+#endif
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     
@@ -2226,7 +2242,11 @@
     gst->priv->target = GST_STATE_VOID_PENDING;
     gst->priv->media_state = PAROLE_STATE_STOPPED;
     gst->priv->aspect_ratio = PAROLE_ASPECT_RATIO_NONE;
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_init (&gst->priv->lock);
+#else
+    gst->priv->lock = g_mutex_new ();
+#endif
     gst->priv->stream = parole_stream_new ();
     gst->priv->tick_id = 0;
     gst->priv->hidecursor_timer = g_timer_new ();
@@ -2330,7 +2350,11 @@
 
 void parole_gst_play_uri (ParoleGst *gst, const gchar *uri, const gchar *subtitles)
 {
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     
     gst->priv->target = GST_STATE_PLAYING;
     parole_stream_init_properties (gst->priv->stream);
@@ -2339,8 +2363,12 @@
 	          "uri", uri,
 		  "subtitles", subtitles,
 		  NULL);
-		  
+
+#if GLIB_CHECK_VERSION (2, 32, 0)		  
     g_mutex_unlock (&gst->priv->lock);
+#else
+    g_mutex_unlock (gst->priv->lock);
+#endif
     
     if ( gst->priv->state_change_id == 0 )
 	gst->priv->state_change_id = g_timeout_add_seconds (20, 
@@ -2381,11 +2409,19 @@
 
 void parole_gst_pause (ParoleGst *gst)
 {
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     
     gst->priv->target = GST_STATE_PAUSED;
-    
+   
+#if GLIB_CHECK_VERSION (2, 32, 0) 
     g_mutex_unlock (&gst->priv->lock);
+#else
+    g_mutex_unlock (gst->priv->lock);
+#endif
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     parole_gst_change_state (gst, GST_STATE_PAUSED);
@@ -2393,11 +2429,19 @@
 
 void parole_gst_resume (ParoleGst *gst)
 {
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     
     gst->priv->target = GST_STATE_PLAYING;
-    
+   
+#if GLIB_CHECK_VERSION (2, 32, 0) 
     g_mutex_unlock (&gst->priv->lock);
+#else
+    g_mutex_unlock (gst->priv->lock);
+#endif
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     parole_gst_change_state (gst, GST_STATE_PLAYING);
@@ -2417,12 +2461,20 @@
 
 void parole_gst_stop (ParoleGst *gst)
 {
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     
     parole_stream_init_properties (gst->priv->stream);
     gst->priv->target = GST_STATE_NULL;
-		  
+
+#if GLIB_CHECK_VERSION (2, 32, 0)		  
     g_mutex_unlock (&gst->priv->lock);
+#else
+    g_mutex_unlock (gst->priv->lock);
+#endif
 
     parole_window_busy_cursor (GTK_WIDGET (gst)->window);
     
