--- gst/mpegaudioparse/gstmpegaudioparse.h.orig	2007-12-17 00:16:56.000000000 -0500
+++ gst/mpegaudioparse/gstmpegaudioparse.h	2007-12-17 00:17:15.000000000 -0500
@@ -40,13 +40,29 @@ G_BEGIN_DECLS
 
 typedef struct _GstMPEGAudioParse GstMPEGAudioParse;
 typedef struct _GstMPEGAudioParseClass GstMPEGAudioParseClass;
+typedef struct _MPEGAudioSeekEntry MPEGAudioSeekEntry;
+typedef struct _MPEGAudioPendingAccurateSeek MPEGAudioPendingAccurateSeek;
+
+
+struct _MPEGAudioSeekEntry {
+  gint64 byte;
+  GstClockTime timestamp;
+};
+
+struct _MPEGAudioPendingAccurateSeek {
+  GstSegment segment;
+  gint64 upstream_start;
+  GstClockTime timestamp_start;
+};
 
 struct _GstMPEGAudioParse {
   GstElement element;
 
   GstPad *sinkpad, *srcpad;
 
+  GstSegment segment;
   GstClockTime next_ts;
+
   /* Offset as supplied by incoming buffers */
   gint64 cur_offset;
 
@@ -62,6 +78,7 @@ struct _GstMPEGAudioParse {
   guint skip; /* number of frames to skip */
   guint bit_rate; /* in kbps */
   gint channels, rate, layer, version;
+  GstClockTime max_bitreservoir;
   gint spf; /* Samples per frame */
 
   gboolean resyncing; /* True when attempting to resync (stricter checks are
@@ -79,9 +96,21 @@ struct _GstMPEGAudioParse {
   guint32 xing_frames;
   GstClockTime xing_total_time;
   guint32 xing_bytes;
+  /* percent -> filepos mapping */
   guchar xing_seek_table[100];
+  /* filepos -> percent mapping */
+  guint16 xing_seek_table_inverse[256];
   guint32 xing_vbr_scale;
   guint   xing_bitrate;
+
+  /* Accurate seeking */
+  GList *seek_table;
+  GMutex *pending_accurate_seeks_lock;
+  GSList *pending_accurate_seeks;
+  gboolean exact_position;
+
+  /* pending segment */
+  GstEvent *pending_segment;
 };
 
 struct _GstMPEGAudioParseClass {
