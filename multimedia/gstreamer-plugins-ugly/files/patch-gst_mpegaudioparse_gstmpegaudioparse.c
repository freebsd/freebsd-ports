--- gst/mpegaudioparse/gstmpegaudioparse.c.orig	2007-12-17 00:16:51.000000000 -0500
+++ gst/mpegaudioparse/gstmpegaudioparse.c	2007-12-17 00:17:13.000000000 -0500
@@ -29,6 +29,7 @@
 GST_DEBUG_CATEGORY_STATIC (mp3parse_debug);
 #define GST_CAT_DEFAULT mp3parse_debug
 
+
 /* elementfactory information */
 static GstElementDetails mp3parse_details = {
   "MPEG1 Audio Parser",
@@ -71,8 +72,9 @@ enum
 
 
 static void gst_mp3parse_class_init (GstMPEGAudioParseClass * klass);
-static void gst_mp3parse_base_init (GstMPEGAudioParseClass * klass);
-static void gst_mp3parse_init (GstMPEGAudioParse * mp3parse);
+static void gst_mp3parse_base_init (gpointer klass);
+static void gst_mp3parse_init (GstMPEGAudioParse * mp3parse,
+    GstMPEGAudioParseClass * klass);
 
 static gboolean gst_mp3parse_sink_event (GstPad * pad, GstEvent * event);
 static GstFlowReturn gst_mp3parse_chain (GstPad * pad, GstBuffer * buffer);
@@ -95,35 +97,11 @@ static gboolean mp3parse_bytepos_to_time
 static gboolean
 mp3parse_total_bytes (GstMPEGAudioParse * mp3parse, gint64 * total);
 
-static GstElementClass *parent_class = NULL;
-
 /*static guint gst_mp3parse_signals[LAST_SIGNAL] = { 0 }; */
 
-GType
-gst_mp3parse_get_type (void)
-{
-  static GType mp3parse_type = 0;
-
-  if (!mp3parse_type) {
-    static const GTypeInfo mp3parse_info = {
-      sizeof (GstMPEGAudioParseClass),
-      (GBaseInitFunc) gst_mp3parse_base_init,
-      NULL,
-      (GClassInitFunc) gst_mp3parse_class_init,
-      NULL,
-      NULL,
-      sizeof (GstMPEGAudioParse),
-      0,
-      (GInstanceInitFunc) gst_mp3parse_init,
-    };
+GST_BOILERPLATE (GstMPEGAudioParse, gst_mp3parse, GstElement, GST_TYPE_ELEMENT);
 
-    mp3parse_type = g_type_register_static (GST_TYPE_ELEMENT,
-        "GstMPEGAudioParse", &mp3parse_info, 0);
-  }
-  return mp3parse_type;
-}
-
-static guint mp3types_bitrates[2][3][16] = {
+static const guint mp3types_bitrates[2][3][16] = {
   {
         {0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448,},
         {0, 32, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384,},
@@ -136,7 +114,7 @@ static guint mp3types_bitrates[2][3][16]
       },
 };
 
-static guint mp3types_freqs[3][3] = { {44100, 48000, 32000},
+static const guint mp3types_freqs[3][3] = { {44100, 48000, 32000},
 {22050, 24000, 16000},
 {11025, 12000, 8000}
 };
@@ -218,13 +196,14 @@ mp3_caps_create (guint layer, guint chan
   new = gst_caps_new_simple ("audio/mpeg",
       "mpegversion", G_TYPE_INT, 1,
       "layer", G_TYPE_INT, layer,
-      "rate", G_TYPE_INT, samplerate, "channels", G_TYPE_INT, channels, NULL);
+      "rate", G_TYPE_INT, samplerate,
+      "channels", G_TYPE_INT, channels, "parsed", G_TYPE_BOOLEAN, TRUE, NULL);
 
   return new;
 }
 
 static void
-gst_mp3parse_base_init (GstMPEGAudioParseClass * klass)
+gst_mp3parse_base_init (gpointer klass)
 {
   GstElementClass *element_class = GST_ELEMENT_CLASS (klass);
 
@@ -265,8 +244,8 @@ gst_mp3parse_reset (GstMPEGAudioParse * 
 {
   mp3parse->skip = 0;
   mp3parse->resyncing = TRUE;
-  mp3parse->cur_offset = -1;
   mp3parse->next_ts = GST_CLOCK_TIME_NONE;
+  mp3parse->cur_offset = -1;
 
   mp3parse->tracked_offset = 0;
   mp3parse->pending_ts = GST_CLOCK_TIME_NONE;
@@ -276,6 +255,7 @@ gst_mp3parse_reset (GstMPEGAudioParse * 
 
   mp3parse->rate = mp3parse->channels = mp3parse->layer = -1;
   mp3parse->version = 1;
+  mp3parse->max_bitreservoir = GST_CLOCK_TIME_NONE;
 
   mp3parse->avg_bitrate = 0;
   mp3parse->bitrate_sum = 0;
@@ -285,21 +265,42 @@ gst_mp3parse_reset (GstMPEGAudioParse * 
 
   mp3parse->xing_flags = 0;
   mp3parse->xing_bitrate = 0;
+
+  if (mp3parse->seek_table) {
+    g_list_foreach (mp3parse->seek_table, (GFunc) g_free, NULL);
+    g_list_free (mp3parse->seek_table);
+    mp3parse->seek_table = NULL;
+  }
+
+  g_mutex_lock (mp3parse->pending_accurate_seeks_lock);
+  if (mp3parse->pending_accurate_seeks) {
+    g_slist_foreach (mp3parse->pending_accurate_seeks, (GFunc) g_free, NULL);
+    g_slist_free (mp3parse->pending_accurate_seeks);
+    mp3parse->pending_accurate_seeks = NULL;
+  }
+  g_mutex_unlock (mp3parse->pending_accurate_seeks_lock);
+
+  if (mp3parse->pending_segment) {
+    GstEvent **eventp = &mp3parse->pending_segment;
+
+    gst_event_replace (eventp, NULL);
+  }
+
+  mp3parse->exact_position = FALSE;
+  gst_segment_init (&mp3parse->segment, GST_FORMAT_TIME);
 }
 
 static void
-gst_mp3parse_init (GstMPEGAudioParse * mp3parse)
+gst_mp3parse_init (GstMPEGAudioParse * mp3parse, GstMPEGAudioParseClass * klass)
 {
   mp3parse->sinkpad =
-      gst_pad_new_from_template (gst_static_pad_template_get
-      (&mp3_sink_template), "sink");
+      gst_pad_new_from_static_template (&mp3_sink_template, "sink");
   gst_pad_set_event_function (mp3parse->sinkpad, gst_mp3parse_sink_event);
   gst_pad_set_chain_function (mp3parse->sinkpad, gst_mp3parse_chain);
   gst_element_add_pad (GST_ELEMENT (mp3parse), mp3parse->sinkpad);
 
   mp3parse->srcpad =
-      gst_pad_new_from_template (gst_static_pad_template_get
-      (&mp3_src_template), "src");
+      gst_pad_new_from_static_template (&mp3_src_template, "src");
   gst_pad_use_fixed_caps (mp3parse->srcpad);
   gst_pad_set_event_function (mp3parse->srcpad, mp3parse_src_event);
   gst_pad_set_query_function (mp3parse->srcpad, mp3parse_src_query);
@@ -307,6 +308,7 @@ gst_mp3parse_init (GstMPEGAudioParse * m
   gst_element_add_pad (GST_ELEMENT (mp3parse), mp3parse->srcpad);
 
   mp3parse->adapter = gst_adapter_new ();
+  mp3parse->pending_accurate_seeks_lock = g_mutex_new ();
 
   gst_mp3parse_reset (mp3parse);
 }
@@ -316,10 +318,14 @@ gst_mp3parse_dispose (GObject * object)
 {
   GstMPEGAudioParse *mp3parse = GST_MP3PARSE (object);
 
+  gst_mp3parse_reset (mp3parse);
+
   if (mp3parse->adapter) {
     g_object_unref (mp3parse->adapter);
     mp3parse->adapter = NULL;
   }
+  g_mutex_free (mp3parse->pending_accurate_seeks_lock);
+  mp3parse->pending_accurate_seeks_lock = NULL;
 
   G_OBJECT_CLASS (parent_class)->dispose (object);
 }
@@ -329,6 +335,7 @@ gst_mp3parse_sink_event (GstPad * pad, G
 {
   gboolean res;
   GstMPEGAudioParse *mp3parse;
+  GstEvent **eventp;
 
   mp3parse = GST_MP3PARSE (gst_pad_get_parent (pad));
 
@@ -343,6 +350,59 @@ gst_mp3parse_sink_event (GstPad * pad, G
       gst_event_parse_new_segment_full (event, &update, &rate, &applied_rate,
           &format, &start, &stop, &pos);
 
+      g_mutex_lock (mp3parse->pending_accurate_seeks_lock);
+      if (format == GST_FORMAT_BYTES && mp3parse->pending_accurate_seeks) {
+        MPEGAudioPendingAccurateSeek *seek = NULL;
+        GSList *node;
+
+        for (node = mp3parse->pending_accurate_seeks; node; node = node->next) {
+          MPEGAudioPendingAccurateSeek *tmp = node->data;
+
+          if (tmp->upstream_start == pos) {
+            seek = tmp;
+            break;
+          }
+        }
+        if (seek) {
+          GstSegment *s = &seek->segment;
+
+          event =
+              gst_event_new_new_segment_full (FALSE, s->rate, s->applied_rate,
+              GST_FORMAT_TIME, s->start, s->stop, s->last_stop);
+
+          mp3parse->segment = seek->segment;
+
+          mp3parse->resyncing = FALSE;
+          mp3parse->cur_offset = pos;
+          mp3parse->next_ts = seek->timestamp_start;
+          mp3parse->pending_ts = GST_CLOCK_TIME_NONE;
+          mp3parse->tracked_offset = 0;
+
+          gst_event_parse_new_segment_full (event, &update, &rate,
+              &applied_rate, &format, &start, &stop, &pos);
+
+          GST_DEBUG_OBJECT (mp3parse,
+              "Pushing accurate newseg rate %g, applied rate %g, "
+              "format %d, start %lld, stop %lld, pos %lld\n", rate,
+              applied_rate, format, start, stop, pos);
+
+          g_free (seek);
+          mp3parse->pending_accurate_seeks =
+              g_slist_delete_link (mp3parse->pending_accurate_seeks, node);
+
+          g_mutex_unlock (mp3parse->pending_accurate_seeks_lock);
+          res = gst_pad_push_event (mp3parse->srcpad, event);
+
+          return res;
+        } else {
+          GST_WARNING_OBJECT (mp3parse,
+              "Accurate seek not possible, didn't get an appropiate upstream segment");
+        }
+      }
+      g_mutex_unlock (mp3parse->pending_accurate_seeks_lock);
+
+      mp3parse->exact_position = FALSE;
+
       if (format == GST_FORMAT_BYTES) {
         GstClockTime seg_start, seg_stop, seg_pos;
 
@@ -356,8 +416,9 @@ gst_mp3parse_sink_event (GstPad * pad, G
               GST_FORMAT_TIME, seg_start, seg_stop, seg_pos);
           format = GST_FORMAT_TIME;
           GST_DEBUG_OBJECT (mp3parse, "Converted incoming segment to TIME. "
-              "start = %" G_GINT64_FORMAT ", stop = %" G_GINT64_FORMAT
-              "pos = %" G_GINT64_FORMAT, seg_start, seg_stop, seg_pos);
+              "start = %" GST_TIME_FORMAT ", stop = %" GST_TIME_FORMAT
+              ", pos = %" GST_TIME_FORMAT, GST_TIME_ARGS (seg_start),
+              GST_TIME_ARGS (seg_stop), GST_TIME_ARGS (seg_pos));
         }
       }
 
@@ -368,6 +429,7 @@ gst_mp3parse_sink_event (GstPad * pad, G
         event = gst_event_new_new_segment_full (update, rate, applied_rate,
             GST_FORMAT_TIME, 0, GST_CLOCK_TIME_NONE, 0);
       }
+
       mp3parse->resyncing = TRUE;
       mp3parse->cur_offset = -1;
       mp3parse->next_ts = GST_CLOCK_TIME_NONE;
@@ -379,12 +441,23 @@ gst_mp3parse_sink_event (GstPad * pad, G
       GST_DEBUG_OBJECT (mp3parse, "Pushing newseg rate %g, applied rate %g, "
           "format %d, start %lld, stop %lld, pos %lld\n",
           rate, applied_rate, format, start, stop, pos);
-      res = gst_pad_push_event (mp3parse->srcpad, event);
+
+      gst_segment_set_newsegment_full (&mp3parse->segment, update, rate,
+          applied_rate, format, start, stop, pos);
+
+      /* save the segment for later, right before we push a new buffer so that
+       * the caps are fixed and the next linked element can receive the segment. */
+      eventp = &mp3parse->pending_segment;
+      gst_event_replace (eventp, event);
+      gst_event_unref (event);
+      res = TRUE;
       break;
     }
     case GST_EVENT_FLUSH_STOP:
       /* Clear our adapter and set up for a new position */
       gst_adapter_clear (mp3parse->adapter);
+      eventp = &mp3parse->pending_segment;
+      gst_event_replace (eventp, NULL);
       res = gst_pad_push_event (mp3parse->srcpad, event);
       break;
     default:
@@ -397,14 +470,26 @@ gst_mp3parse_sink_event (GstPad * pad, G
   return res;
 }
 
+static MPEGAudioSeekEntry *
+mp3parse_seek_table_last_entry (GstMPEGAudioParse * mp3parse)
+{
+  MPEGAudioSeekEntry *ret = NULL;
+
+  if (mp3parse->seek_table) {
+    ret = mp3parse->seek_table->data;
+  }
+
+  return ret;
+}
+
 /* Prepare a buffer of the indicated size, timestamp it and output */
 static GstFlowReturn
 gst_mp3parse_emit_frame (GstMPEGAudioParse * mp3parse, guint size)
 {
   GstBuffer *outbuf;
   guint bitrate;
-
-  GST_DEBUG_OBJECT (mp3parse, "pushing buffer of %d bytes", size);
+  GstFlowReturn ret = GST_FLOW_OK;
+  GstClockTime push_start;
 
   outbuf = gst_adapter_take_buffer (mp3parse->adapter, size);
 
@@ -456,6 +541,22 @@ gst_mp3parse_emit_frame (GstMPEGAudioPar
     }
   }
 
+  if (GST_BUFFER_TIMESTAMP (outbuf) == 0)
+    mp3parse->exact_position = TRUE;
+
+  if (mp3parse->exact_position && (!mp3parse->seek_table ||
+          (mp3parse_seek_table_last_entry (mp3parse))->byte <
+          GST_BUFFER_OFFSET (outbuf))) {
+    MPEGAudioSeekEntry *entry = g_new0 (MPEGAudioSeekEntry, 1);
+
+    entry->byte = mp3parse->cur_offset;
+    entry->timestamp = GST_BUFFER_TIMESTAMP (outbuf);
+    mp3parse->seek_table = g_list_prepend (mp3parse->seek_table, entry);
+    GST_DEBUG_OBJECT (mp3parse, "Adding index entry %" GST_TIME_FORMAT
+        " @ offset 0x%08" G_GINT64_MODIFIER "x",
+        GST_TIME_ARGS (entry->timestamp), entry->byte);
+  }
+
   /* Update our byte offset tracking */
   if (mp3parse->cur_offset != -1) {
     mp3parse->cur_offset += size;
@@ -483,7 +584,53 @@ gst_mp3parse_emit_frame (GstMPEGAudioPar
         mp3parse->srcpad, taglist);
   }
 
-  return gst_pad_push (mp3parse->srcpad, outbuf);
+  /* We start pushing 9 frames earlier (29 frames for MPEG2) than
+   * segment start to be able to decode the first frame we want.
+   * 9 (29) frames are the theoretical maximum of frames that contain
+   * data for the current frame (bit reservoir).
+   */
+
+  if (mp3parse->segment.start == 0) {
+    push_start = 0;
+  } else if (GST_CLOCK_TIME_IS_VALID (mp3parse->max_bitreservoir)) {
+    if (mp3parse->segment.start > mp3parse->max_bitreservoir)
+      push_start = mp3parse->segment.start - mp3parse->max_bitreservoir;
+    else
+      push_start = 0;
+  } else {
+    push_start = mp3parse->segment.start;
+  }
+
+  if (G_UNLIKELY ((GST_CLOCK_TIME_IS_VALID (push_start) &&
+              GST_BUFFER_TIMESTAMP (outbuf) + GST_BUFFER_DURATION (outbuf)
+              < push_start)
+          || (GST_CLOCK_TIME_IS_VALID (mp3parse->segment.stop)
+              && GST_BUFFER_TIMESTAMP (outbuf) >= mp3parse->segment.stop))) {
+    GST_DEBUG_OBJECT (mp3parse,
+        "Buffer outside of configured segment range %" GST_TIME_FORMAT
+        " to %" GST_TIME_FORMAT ", dropping, timestamp %"
+        GST_TIME_FORMAT ", offset 0x%08" G_GINT64_MODIFIER "x",
+        GST_TIME_ARGS (push_start), GST_TIME_ARGS (mp3parse->segment.stop),
+        GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (outbuf)),
+        GST_BUFFER_OFFSET (outbuf));
+    gst_buffer_unref (outbuf);
+    ret = GST_FLOW_OK;
+  } else {
+    GST_DEBUG_OBJECT (mp3parse,
+        "pushing buffer of %d bytes, timestamp %" GST_TIME_FORMAT
+        ", offset 0x%08" G_GINT64_MODIFIER "x", size,
+        GST_TIME_ARGS (GST_BUFFER_TIMESTAMP (outbuf)),
+        GST_BUFFER_OFFSET (outbuf));
+    mp3parse->segment.last_stop = GST_BUFFER_TIMESTAMP (outbuf);
+    /* push any pending segment now */
+    if (mp3parse->pending_segment) {
+      gst_pad_push_event (mp3parse->srcpad, mp3parse->pending_segment);
+      mp3parse->pending_segment = NULL;
+    }
+    ret = gst_pad_push (mp3parse->srcpad, outbuf);
+  }
+
+  return ret;
 }
 
 #define XING_FRAMES_FLAG     0x0001
@@ -610,14 +757,41 @@ gst_mp3parse_handle_first_frame (GstMPEG
       mp3parse->xing_bytes = 0;
 
     if (xing_flags & XING_TOC_FLAG) {
-      gint i;
+      int i, percent = 0;
+      guchar *table = mp3parse->xing_seek_table;
+
+      /* xing seek table: percent time -> 1/256 bytepos */
+      memcpy (mp3parse->xing_seek_table, data, 100);
 
-      for (i = 0; i < 100; i++) {
-        mp3parse->xing_seek_table[i] = data[0];
-        data++;
+      /* build inverse table: 1/256 bytepos -> 1/100 percent time */
+      for (i = 0; i < 256; i++) {
+        while (percent < 99 && table[percent + 1] <= i)
+          percent++;
+
+        if (table[percent] == i) {
+          mp3parse->xing_seek_table_inverse[i] = percent * 100;
+        } else if (table[percent] < i && percent < 99) {
+          gdouble fa, fb, fx;
+          gint a = percent, b = percent + 1;
+
+          fa = table[a];
+          fb = table[b];
+          fx = (b - a) / (fb - fa) * (i - fa) + a;
+          mp3parse->xing_seek_table_inverse[i] = (guint16) (fx * 100);
+        } else if (percent == 98 && table[percent + 1] <= i) {
+          gdouble fa, fb, fx;
+          gint a = percent + 1, b = 100;
+
+          fa = table[a];
+          fb = 256.0;
+          fx = (b - a) / (fb - fa) * (i - fa) + a;
+          mp3parse->xing_seek_table_inverse[i] = (guint16) (fx * 100);
+        }
       }
+      data += 100;
     } else {
       memset (mp3parse->xing_seek_table, 0, 100);
+      memset (mp3parse->xing_seek_table_inverse, 0, 256);
     }
 
     if (xing_flags & XING_VBR_SCALE_FLAG) {
@@ -777,6 +951,9 @@ gst_mp3parse_chain (GstPad * pad, GstBuf
           mp3parse->spf = 1152;
       }
 
+      mp3parse->max_bitreservoir = gst_util_uint64_scale (GST_SECOND,
+          ((version == 1) ? 10 : 30) * mp3parse->spf, mp3parse->rate);
+
       /* Check the first frame for a Xing header to get our total length */
       if (mp3parse->frame_count == 0) {
         /* For the first frame in the file, look for a Xing frame after 
@@ -930,6 +1107,45 @@ gst_mp3parse_change_state (GstElement * 
   return result;
 }
 
+static gboolean
+mp3parse_total_bytes (GstMPEGAudioParse * mp3parse, gint64 * total)
+{
+  GstFormat fmt = GST_FORMAT_BYTES;
+
+  if (gst_pad_query_peer_duration (mp3parse->sinkpad, &fmt, total))
+    return TRUE;
+
+  if (mp3parse->xing_flags & XING_BYTES_FLAG) {
+    *total = mp3parse->xing_bytes;
+    return TRUE;
+  }
+
+  return FALSE;
+}
+
+static gboolean
+mp3parse_total_time (GstMPEGAudioParse * mp3parse, GstClockTime * total)
+{
+  gint64 total_bytes;
+
+  *total = GST_CLOCK_TIME_NONE;
+
+  if (mp3parse->xing_flags & XING_FRAMES_FLAG) {
+    *total = mp3parse->xing_total_time;
+    return TRUE;
+  }
+
+  /* Calculate time from the measured bitrate */
+  if (!mp3parse_total_bytes (mp3parse, &total_bytes))
+    return FALSE;
+
+  if (total_bytes != -1
+      && !mp3parse_bytepos_to_time (mp3parse, total_bytes, total))
+    return FALSE;
+
+  return TRUE;
+}
+
 /* Convert a timestamp to the file position required to start decoding that
  * timestamp. For now, this just uses the avg bitrate. Later, use an 
  * incrementally accumulated seek table */
@@ -937,12 +1153,38 @@ static gboolean
 mp3parse_time_to_bytepos (GstMPEGAudioParse * mp3parse, GstClockTime ts,
     gint64 * bytepos)
 {
+  gint64 total_bytes;
+  GstClockTime total_time;
+
   /* -1 always maps to -1 */
   if (ts == -1) {
     *bytepos = -1;
     return TRUE;
   }
 
+  /* If XING seek table exists use this for time->byte conversion */
+  if ((mp3parse->xing_flags & XING_TOC_FLAG) &&
+      mp3parse_total_bytes (mp3parse, &total_bytes) &&
+      mp3parse_total_time (mp3parse, &total_time)) {
+    gdouble fa, fb, fx;
+    gdouble percent =
+        CLAMP ((100.0 * gst_util_guint64_to_gdouble (ts)) /
+        gst_util_guint64_to_gdouble (total_time), 0.0, 100.0);
+    gint index = CLAMP (percent, 0, 99);
+
+    fa = mp3parse->xing_seek_table[index];
+    if (index < 99)
+      fb = mp3parse->xing_seek_table[index + 1];
+    else
+      fb = 256.0;
+
+    fx = fa + (fb - fa) * (percent - index);
+
+    *bytepos = (1.0 / 256.0) * fx * total_bytes;
+
+    return TRUE;
+  }
+
   if (mp3parse->avg_bitrate == 0)
     goto no_bitrate;
 
@@ -958,6 +1200,9 @@ static gboolean
 mp3parse_bytepos_to_time (GstMPEGAudioParse * mp3parse,
     gint64 bytepos, GstClockTime * ts)
 {
+  gint64 total_bytes;
+  GstClockTime total_time;
+
   if (bytepos == -1) {
     *ts = GST_CLOCK_TIME_NONE;
     return TRUE;
@@ -968,61 +1213,33 @@ mp3parse_bytepos_to_time (GstMPEGAudioPa
     return TRUE;
   }
 
-  /* Cannot convert anything except 0 if we don't have a bitrate yet */
-  if (mp3parse->avg_bitrate == 0)
-    return FALSE;
-
-  *ts = (GstClockTime) gst_util_uint64_scale (GST_SECOND, bytepos * 8,
-      mp3parse->avg_bitrate);
-  return TRUE;
-}
-
-static gboolean
-mp3parse_total_bytes (GstMPEGAudioParse * mp3parse, gint64 * total)
-{
-  GstQuery *query;
-  GstPad *peer;
-
-  if ((peer = gst_pad_get_peer (mp3parse->sinkpad)) != NULL) {
-    query = gst_query_new_duration (GST_FORMAT_BYTES);
-    gst_query_set_duration (query, GST_FORMAT_BYTES, -1);
-
-    if (gst_pad_query (peer, query)) {
-      gst_object_unref (peer);
-      gst_query_parse_duration (query, NULL, total);
-      return TRUE;
-    }
-    gst_object_unref (peer);
-  }
-
-  if (mp3parse->xing_flags & XING_BYTES_FLAG) {
-    *total = mp3parse->xing_bytes;
-    return TRUE;
-  }
-
-  return FALSE;
-}
+  /* If XING seek table exists use this for byte->time conversion */
+  if ((mp3parse->xing_flags & XING_TOC_FLAG) &&
+      mp3parse_total_bytes (mp3parse, &total_bytes) &&
+      mp3parse_total_time (mp3parse, &total_time)) {
+    gdouble fa, fb, fx;
+    gdouble pos = CLAMP ((bytepos * 256.0) / total_bytes, 0.0, 256.0);
+    gint index = CLAMP (pos, 0, 255);
+
+    fa = mp3parse->xing_seek_table_inverse[index];
+    if (index < 255)
+      fb = mp3parse->xing_seek_table_inverse[index + 1];
+    else
+      fb = 10000.0;
 
-static gboolean
-mp3parse_total_time (GstMPEGAudioParse * mp3parse, GstClockTime * total)
-{
-  gint64 total_bytes;
+    fx = fa + (fb - fa) * (pos - index);
 
-  *total = GST_CLOCK_TIME_NONE;
+    *ts = (1.0 / 10000.0) * fx * gst_util_guint64_to_gdouble (total_time);
 
-  if (mp3parse->xing_flags & XING_FRAMES_FLAG) {
-    *total = mp3parse->xing_total_time;
     return TRUE;
   }
 
-  /* Calculate time from the measured bitrate */
-  if (!mp3parse_total_bytes (mp3parse, &total_bytes))
-    return FALSE;
-
-  if (total_bytes != -1
-      && !mp3parse_bytepos_to_time (mp3parse, total_bytes, total))
+  /* Cannot convert anything except 0 if we don't have a bitrate yet */
+  if (mp3parse->avg_bitrate == 0)
     return FALSE;
 
+  *ts = (GstClockTime) gst_util_uint64_scale (GST_SECOND, bytepos * 8,
+      mp3parse->avg_bitrate);
   return TRUE;
 }
 
@@ -1036,11 +1253,12 @@ mp3parse_handle_seek (GstMPEGAudioParse 
   gint64 cur, stop;
   gint64 byte_cur, byte_stop;
 
-  /* FIXME: Use GstSegment for tracking our position */
-
   gst_event_parse_seek (event, &rate, &format, &flags, &cur_type, &cur,
       &stop_type, &stop);
 
+  GST_DEBUG_OBJECT (mp3parse, "Performing seek to %" GST_TIME_FORMAT,
+      GST_TIME_ARGS (cur));
+
   /* For any format other than TIME, see if upstream handles
    * it directly or fail. For TIME, try upstream, but do it ourselves if
    * it fails upstream */
@@ -1055,6 +1273,90 @@ mp3parse_handle_seek (GstMPEGAudioParse 
 
   /* Handle TIME based seeks by converting to a BYTE position */
 
+  /* For accurate seeking get the frame 9 (MPEG1) or 29 (MPEG2) frames
+   * before the one we want to seek to and push them all to the decoder.
+   *
+   * This is necessary because of the bit reservoir. See
+   * http://www.mars.org/mailman/public/mad-dev/2002-May/000634.html
+   *
+   */
+
+  if (flags & GST_SEEK_FLAG_ACCURATE) {
+    MPEGAudioPendingAccurateSeek *seek =
+        g_new0 (MPEGAudioPendingAccurateSeek, 1);
+    GstClockTime start;
+
+    seek->segment = mp3parse->segment;
+
+    gst_segment_set_seek (&seek->segment, rate, GST_FORMAT_TIME,
+        flags, cur_type, cur, stop_type, stop, NULL);
+
+    if (!mp3parse->seek_table) {
+      byte_cur = 0;
+      byte_stop = -1;
+      start = 0;
+    } else {
+      MPEGAudioSeekEntry *entry = NULL, *start_entry = NULL, *stop_entry = NULL;
+      GList *start_node, *stop_node;
+
+      for (start_node = mp3parse->seek_table; start_node;
+          start_node = start_node->next) {
+        entry = start_node->data;
+
+        if (cur - mp3parse->max_bitreservoir >= entry->timestamp) {
+          start_entry = entry;
+          break;
+        }
+      }
+
+      if (!start_entry) {
+        start_entry = mp3parse->seek_table->data;
+        start = start_entry->timestamp;
+        byte_cur = start_entry->byte;
+      } else {
+        start = start_entry->timestamp;
+        byte_cur = start_entry->byte;
+      }
+
+      for (stop_node = mp3parse->seek_table; stop_node;
+          stop_node = stop_node->next) {
+        entry = stop_node->data;
+
+        if (stop >= entry->timestamp) {
+          stop_node = stop_node->prev;
+          stop_entry = (stop_node) ? stop_node->data : NULL;
+          break;
+        }
+      }
+
+      if (!stop_entry) {
+        byte_stop = -1;
+      } else {
+        byte_stop = stop_entry->byte;
+      }
+
+    }
+    g_mutex_lock (mp3parse->pending_accurate_seeks_lock);
+    event = gst_event_new_seek (rate, GST_FORMAT_BYTES, flags, cur_type,
+        byte_cur, stop_type, byte_stop);
+    if (gst_pad_push_event (mp3parse->sinkpad, event)) {
+      mp3parse->exact_position = TRUE;
+      seek->upstream_start = byte_cur;
+      seek->timestamp_start = start;
+      mp3parse->pending_accurate_seeks =
+          g_slist_prepend (mp3parse->pending_accurate_seeks, seek);
+      g_mutex_unlock (mp3parse->pending_accurate_seeks_lock);
+      return TRUE;
+    } else {
+      g_mutex_unlock (mp3parse->pending_accurate_seeks_lock);
+      mp3parse->exact_position = TRUE;
+      g_free (seek);
+      return TRUE;
+    }
+  }
+
+  mp3parse->exact_position = FALSE;
+
   /* Convert the TIME to the appropriate BYTE position at which to resume
    * decoding. */
   if (!mp3parse_time_to_bytepos (mp3parse, (GstClockTime) cur, &byte_cur))
