--- ext/dirac/gstdiracdec.cc.orig	Mon Feb 28 22:04:33 2005
+++ ext/dirac/gstdiracdec.cc	Mon Feb 28 22:12:15 2005
@@ -253,13 +253,18 @@
 
       case STATE_SEQUENCE:{
         guint8 *buf[3];
+        gint fps_num, fps_denom;
+
+        fps_num = diracdec->decoder->seq_params.frame_rate.numerator;
+  	fps_denom = diracdec->decoder->seq_params.frame_rate.denominator;
 
         /* start-of-sequence - allocate buffer */
         if (!gst_diracdec_link (diracdec,
                 diracdec->decoder->seq_params.width,
                 diracdec->decoder->seq_params.height,
+                (gdouble) fps_num / (gdouble) fps_denom,
                 gst_diracdec_chroma_to_fourcc (diracdec->decoder->seq_params.
-                    chroma), diracdec->decoder->seq_params.frame_rate)) {
+                    chroma))) {
           GST_ELEMENT_ERROR (diracdec, CORE, NEGOTIATION, (NULL),
               ("Failed to set caps to %dx%d @ %d fps (format=" GST_FOURCC_FORMAT
                   "/%d)", diracdec->decoder->seq_params.width,
