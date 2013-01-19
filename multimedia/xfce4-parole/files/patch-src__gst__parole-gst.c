--- ./src/gst/parole-gst.c.orig	2013-01-07 10:15:53.000000000 +0000
+++ ./src/gst/parole-gst.c	2013-01-15 22:53:07.000000000 +0000
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
@@ -1435,22 +1443,36 @@
     dialog = GTK_MESSAGE_DIALOG(gtk_message_dialog_new_with_markup(
                             NULL,
                             GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
+#if defined(__linux__)
                             GTK_MESSAGE_QUESTION,
+#elif defined(__FreeBSD__)
+                            GTK_MESSAGE_WARNING,
+#endif
                             GTK_BUTTONS_NONE,
                             "<b><big>%s</big></b>", 
                             _("Additional software is required.")
                             ));
-                            
+    
+#if defined(__linux__)                            
     gtk_dialog_add_buttons( GTK_DIALOG(dialog), 
                             _("Don't Install"),
                             GTK_RESPONSE_REJECT,
                             _("Install"), 
                             GTK_RESPONSE_ACCEPT,
                             NULL );
+#elif defined(__FreeBSD__)
+    gtk_dialog_add_button( GTK_DIALOG(dialog), 
+                            GTK_STOCK_OK,
+                            GTK_RESPONSE_OK);
+#endif
     
     gtk_message_dialog_format_secondary_markup(dialog,
+#if defined(__linux__)
                                              "Parole needs <b>%s</b> to play this file.\n"
                                              "It can be installed automatically.",
+#elif defined(__FreeBSD__)
+                                             "Parole needs <b>%s</b> to play this file.",
+#endif
                                              desc);
     
     return GTK_DIALOG(dialog);
@@ -1561,7 +1583,7 @@
 	             
 	             gst_install_plugins_context_free(ctx);
 	        }
-	        else if ( response == GTK_RESPONSE_REJECT )
+	        else if ( (response == GTK_RESPONSE_REJECT) || (response == GTK_RESPONSE_OK) )
 	            gtk_widget_destroy(GTK_WIDGET(dialog));
         }
 	    break;
@@ -1876,11 +1898,19 @@
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
     
@@ -2226,7 +2256,11 @@
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
@@ -2330,7 +2364,11 @@
 
 void parole_gst_play_uri (ParoleGst *gst, const gchar *uri, const gchar *subtitles)
 {
+#if GLIB_CHECK_VERSION (2, 32, 0)
     g_mutex_lock (&gst->priv->lock);
+#else
+    g_mutex_lock (gst->priv->lock);
+#endif
     
     gst->priv->target = GST_STATE_PLAYING;
     parole_stream_init_properties (gst->priv->stream);
@@ -2339,8 +2377,12 @@
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
@@ -2381,11 +2423,19 @@
 
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
@@ -2393,11 +2443,19 @@
 
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
@@ -2417,12 +2475,20 @@
 
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
     
