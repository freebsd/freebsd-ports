--- ext/vorbis/vorbisparse.c.orig	Wed Jun 23 23:49:17 2004
+++ ext/vorbis/vorbisparse.c	Wed Jun 23 23:50:16 2004
@@ -103,6 +103,9 @@
 vorbis_parse_set_header_on_caps (GstVorbisParse * parse, GstCaps * caps)
 {
   GstBuffer *buf1, *buf2, *buf3;
+  GstStructure *structure;
+  GValue list = { 0 };
+  GValue value = { 0 };
 
   g_assert (parse);
   g_assert (parse->streamheader);
@@ -115,9 +118,7 @@
   buf3 = parse->streamheader->next->next->data;
   g_assert (buf3);
 
-  GstStructure *structure = gst_caps_get_structure (caps, 0);
-  GValue list = { 0 };
-  GValue value = { 0 };
+  structure = gst_caps_get_structure (caps, 0);
 
   /* mark buffers */
   GST_BUFFER_FLAG_SET (buf1, GST_BUFFER_IN_CAPS);
