--- xfburn/xfburn-transcoder-gst.c.orig	2017-12-14 12:34:57 UTC
+++ xfburn/xfburn-transcoder-gst.c
@@ -221,8 +221,8 @@ xfburn_transcoder_gst_init (XfburnTranscoderGst * obj)
 
   /* if the mutex is locked, then we're not currently seeking
    * information from gst */
+  /* Actual locking in prepare and finish */
   g_mutex_init (&priv->gst_mutex);
-  g_mutex_lock (&priv->gst_mutex);
 
   priv->discoverer = gst_discoverer_new(GST_SECOND, NULL);
 }
@@ -492,19 +492,9 @@ bus_call (GstBus *bus, GstMessage *msg, gpointer data)
 
           if (strcmp (GST_OBJECT_NAME (GST_MESSAGE_SRC (msg)), "decoder") != 0)
             break;
-          
-          if (!g_mutex_trylock (&priv->gst_mutex)) {
-            g_critical ("Lock held by another thread, can't signal transcoding start!");
-            break;
-          } else {
-#if DEBUG_GST > 0
-            DBG ("Locked mutex to signal transcoding start");
-#endif
-          }
 
           priv->gst_done = TRUE;
           g_cond_signal (&priv->gst_cond);
-          g_mutex_unlock (&priv->gst_mutex);
           break;
       } /* switch of priv->state */
 
@@ -835,6 +825,8 @@ prepare (XfburnTranscoder *trans, GError **error)
   gboolean ret;
   gint64 end_time;
 
+  g_mutex_lock(&priv->gst_mutex);
+
   priv->tracks = g_slist_reverse (priv->tracks);
 
   priv->state = XFBURN_TRANSCODER_GST_STATE_TRANSCODE_START;
@@ -933,6 +925,8 @@ finish (XfburnTranscoder *trans)
   }
   */
   recreate_pipeline (gst);
+
+  g_mutex_unlock (&priv->gst_mutex);
 }
 
 
