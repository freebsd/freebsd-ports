--- video/out/vo_lavc.c.orig	2016-04-11 17:10:54 UTC
+++ video/out/vo_lavc.c
@@ -37,6 +37,7 @@ struct priv {
     uint8_t *buffer;
     size_t buffer_size;
     AVStream *stream;
+    AVCodecContext *codec;
     int have_first_packet;
 
     int harddup;
@@ -108,14 +109,14 @@ static int reconfig(struct vo *vo, struc
          * warning here. We choose to ignore that; just because ffmpeg currently
          * uses a plain 'int' for these struct fields, it doesn't mean it always
          * will */
-        if (width == vc->stream->codec->width &&
-                height == vc->stream->codec->height) {
-            if (aspect.num != vc->stream->codec->sample_aspect_ratio.num ||
-                    aspect.den != vc->stream->codec->sample_aspect_ratio.den) {
+        if (width == vc->codec->width &&
+                height == vc->codec->height) {
+            if (aspect.num != vc->codec->sample_aspect_ratio.num ||
+                    aspect.den != vc->codec->sample_aspect_ratio.den) {
                 /* aspect-only changes are not critical */
                 MP_WARN(vo, "unsupported pixel aspect ratio change from %d:%d to %d:%d\n",
-                       vc->stream->codec->sample_aspect_ratio.num,
-                       vc->stream->codec->sample_aspect_ratio.den,
+                       vc->codec->sample_aspect_ratio.num,
+                       vc->codec->sample_aspect_ratio.den,
                        aspect.num, aspect.den);
             }
             goto done;
@@ -144,18 +145,20 @@ static int reconfig(struct vo *vo, struc
         goto error;
     }
 
-    vc->stream = encode_lavc_alloc_stream(vo->encode_lavc_ctx,
-                                          AVMEDIA_TYPE_VIDEO);
-    vc->stream->sample_aspect_ratio = vc->stream->codec->sample_aspect_ratio =
+    if (encode_lavc_alloc_stream(vo->encode_lavc_ctx,
+                                 AVMEDIA_TYPE_VIDEO,
+                                 &vc->stream, &vc->codec) < 0)
+        goto error;
+    vc->stream->sample_aspect_ratio = vc->codec->sample_aspect_ratio =
             aspect;
-    vc->stream->codec->width = width;
-    vc->stream->codec->height = height;
-    vc->stream->codec->pix_fmt = pix_fmt;
+    vc->codec->width = width;
+    vc->codec->height = height;
+    vc->codec->pix_fmt = pix_fmt;
 
-    encode_lavc_set_csp(vo->encode_lavc_ctx, vc->stream, params->colorspace);
-    encode_lavc_set_csp_levels(vo->encode_lavc_ctx, vc->stream, params->colorlevels);
+    encode_lavc_set_csp(vo->encode_lavc_ctx, vc->codec, params->colorspace);
+    encode_lavc_set_csp_levels(vo->encode_lavc_ctx, vc->codec, params->colorlevels);
 
-    if (encode_lavc_open_codec(vo->encode_lavc_ctx, vc->stream) < 0)
+    if (encode_lavc_open_codec(vo->encode_lavc_ctx, vc->codec) < 0)
         goto error;
 
     vc->buffer_size = 6 * width * height + 200;
@@ -204,7 +207,7 @@ static void write_packet(struct vo *vo, 
         packet->stream_index = vc->stream->index;
         if (packet->pts != AV_NOPTS_VALUE) {
             packet->pts = av_rescale_q(packet->pts,
-                                       vc->stream->codec->time_base,
+                                       vc->codec->time_base,
                                        vc->stream->time_base);
         } else {
             MP_VERBOSE(vo, "codec did not provide pts\n");
@@ -213,12 +216,12 @@ static void write_packet(struct vo *vo, 
         }
         if (packet->dts != AV_NOPTS_VALUE) {
             packet->dts = av_rescale_q(packet->dts,
-                                       vc->stream->codec->time_base,
+                                       vc->codec->time_base,
                                        vc->stream->time_base);
         }
         if (packet->duration > 0) {
             packet->duration = av_rescale_q(packet->duration,
-                                       vc->stream->codec->time_base,
+                                       vc->codec->time_base,
                                        vc->stream->time_base);
         } else {
             // HACK: libavformat calculates dts wrong if the initial packet
@@ -226,15 +229,16 @@ static void write_packet(struct vo *vo, 
             // have b-frames!
             if (!packet->duration)
                 if (!vc->have_first_packet)
-                    if (vc->stream->codec->has_b_frames
-                            || vc->stream->codec->max_b_frames)
+                    if (vc->codec->has_b_frames
+                            || vc->codec->max_b_frames)
                         if (vc->stream->time_base.num * 1000LL <=
                                 vc->stream->time_base.den)
                             packet->duration = FFMAX(1, av_rescale_q(1,
-                                 vc->stream->codec->time_base, vc->stream->time_base));
+                                 vc->codec->time_base, vc->stream->time_base));
         }
 
-        if (encode_lavc_write_frame(vo->encode_lavc_ctx, packet) < 0) {
+        if (encode_lavc_write_frame(vo->encode_lavc_ctx,
+                                    vc->stream, packet) < 0) {
             MP_ERR(vo, "error writing\n");
             return;
         }
@@ -251,23 +255,23 @@ static int encode_video(struct vo *vo, A
             return 0;
         memcpy(vc->buffer, frame, sizeof(AVPicture));
         MP_DBG(vo, "got pts %f\n",
-               frame->pts * (double) vc->stream->codec->time_base.num /
-                            (double) vc->stream->codec->time_base.den);
+               frame->pts * (double) vc->codec->time_base.num /
+                            (double) vc->codec->time_base.den);
         packet->size = sizeof(AVPicture);
         return packet->size;
     } else {
         int got_packet = 0;
-        int status = avcodec_encode_video2(vc->stream->codec, packet,
+        int status = avcodec_encode_video2(vc->codec, packet,
                                            frame, &got_packet);
         int size = (status < 0) ? status : got_packet ? packet->size : 0;
 
         if (frame)
             MP_DBG(vo, "got pts %f; out size: %d\n",
-                   frame->pts * (double) vc->stream->codec->time_base.num /
-                   (double) vc->stream->codec->time_base.den, size);
+                   frame->pts * (double) vc->codec->time_base.num /
+                   (double) vc->codec->time_base.den, size);
 
         if (got_packet)
-            encode_lavc_write_stats(vo->encode_lavc_ctx, vc->stream);
+            encode_lavc_write_stats(vo->encode_lavc_ctx, vc->codec);
         return size;
     }
 }
@@ -295,7 +299,7 @@ static void draw_image_unlocked(struct v
         pts = vc->expected_next_pts;
     }
 
-    avc = vc->stream->codec;
+    avc = vc->codec;
 
     if (vc->worst_time_base.den == 0) {
         //if (avc->time_base.num / avc->time_base.den >= vc->stream->time_base.num / vc->stream->time_base.den)
@@ -376,7 +380,7 @@ static void draw_image_unlocked(struct v
     }
     vc->lastpts = outpts;
     ectx->last_video_in_pts = pts;
-    frameipts = floor((outpts + encode_lavc_getoffset(ectx, vc->stream))
+    frameipts = floor((outpts + encode_lavc_getoffset(ectx, vc->codec))
                       / timeunit + 0.5);
 
     // calculate expected pts of next video frame
@@ -396,7 +400,7 @@ static void draw_image_unlocked(struct v
             MP_INFO(vo, "--oneverdrop increased pts by %d\n",
                     (int) (vc->lastipts - frameipts + step));
             frameipts = vc->lastipts + step;
-            vc->lastpts = frameipts * timeunit - encode_lavc_getoffset(ectx, vc->stream);
+            vc->lastpts = frameipts * timeunit - encode_lavc_getoffset(ectx, vc->codec);
         }
     }
 
