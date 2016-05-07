--- audio/out/ao_lavc.c.orig	2016-04-11 17:10:54 UTC
+++ audio/out/ao_lavc.c
@@ -42,6 +42,7 @@ struct priv {
     uint8_t *buffer;
     size_t buffer_size;
     AVStream *stream;
+    AVCodecContext *codec;
     int pcmhack;
     int aframesize;
     int aframecount;
@@ -98,15 +99,14 @@ static int init(struct ao *ao)
 
     pthread_mutex_lock(&ao->encode_lavc_ctx->lock);
 
-    ac->stream = encode_lavc_alloc_stream(ao->encode_lavc_ctx,
-                                          AVMEDIA_TYPE_AUDIO);
-
-    if (!ac->stream) {
-        MP_ERR(ao, "could not get a new audio stream\n");
-        goto fail;
+    if (encode_lavc_alloc_stream(ao->encode_lavc_ctx,
+                                 AVMEDIA_TYPE_AUDIO,
+                                 &ac->stream, &ac->codec) < 0) {
+      MP_ERR(ao, "could not get a new audio stream\n");
+      goto fail;
     }
 
-    codec = encode_lavc_get_codec(ao->encode_lavc_ctx, ac->stream);
+    codec = ao->encode_lavc_ctx->ac;
 
     int samplerate = af_select_best_samplerate(ao->samplerate,
                                                codec->supported_samplerates);
@@ -118,40 +118,40 @@ static int init(struct ao *ao)
     // Using codec->time_bvase is deprecated, but needed for older lavf.
     ac->stream->time_base.num = 1;
     ac->stream->time_base.den = ao->samplerate;
-    ac->stream->codec->time_base.num = 1;
-    ac->stream->codec->time_base.den = ao->samplerate;
+    ac->codec->time_base.num = 1;
+    ac->codec->time_base.den = ao->samplerate;
 
-    ac->stream->codec->sample_rate = ao->samplerate;
+    ac->codec->sample_rate = ao->samplerate;
 
     struct mp_chmap_sel sel = {0};
     mp_chmap_sel_add_any(&sel);
     if (!ao_chmap_sel_adjust(ao, &sel, &ao->channels))
         goto fail;
     mp_chmap_reorder_to_lavc(&ao->channels);
-    ac->stream->codec->channels = ao->channels.num;
-    ac->stream->codec->channel_layout = mp_chmap_to_lavc(&ao->channels);
+    ac->codec->channels = ao->channels.num;
+    ac->codec->channel_layout = mp_chmap_to_lavc(&ao->channels);
 
-    ac->stream->codec->sample_fmt = AV_SAMPLE_FMT_NONE;
+    ac->codec->sample_fmt = AV_SAMPLE_FMT_NONE;
 
     select_format(ao, codec);
 
     ac->sample_size = af_fmt_to_bytes(ao->format);
-    ac->stream->codec->sample_fmt = af_to_avformat(ao->format);
-    ac->stream->codec->bits_per_raw_sample = ac->sample_size * 8;
+    ac->codec->sample_fmt = af_to_avformat(ao->format);
+    ac->codec->bits_per_raw_sample = ac->sample_size * 8;
 
-    if (encode_lavc_open_codec(ao->encode_lavc_ctx, ac->stream) < 0)
+    if (encode_lavc_open_codec(ao->encode_lavc_ctx, ac->codec) < 0)
         goto fail;
 
     ac->pcmhack = 0;
-    if (ac->stream->codec->frame_size <= 1)
-        ac->pcmhack = av_get_bits_per_sample(ac->stream->codec->codec_id) / 8;
+    if (ac->codec->frame_size <= 1)
+        ac->pcmhack = av_get_bits_per_sample(ac->codec->codec_id) / 8;
 
     if (ac->pcmhack) {
         ac->aframesize = 16384; // "enough"
         ac->buffer_size =
             ac->aframesize * ac->pcmhack * ao->channels.num * 2 + 200;
     } else {
-        ac->aframesize = ac->stream->codec->frame_size;
+        ac->aframesize = ac->codec->frame_size;
         ac->buffer_size =
             ac->aframesize * ac->sample_size * ao->channels.num * 2 + 200;
     }
@@ -203,7 +203,7 @@ static void uninit(struct ao *ao)
         double outpts = ac->expected_next_pts;
         if (!ectx->options->rawts && ectx->options->copyts)
             outpts += ectx->discontinuity_pts_offset;
-        outpts += encode_lavc_getoffset(ectx, ac->stream);
+        outpts += encode_lavc_getoffset(ectx, ac->codec);
         while (encode(ao, outpts, NULL) > 0) ;
     }
 
@@ -252,25 +252,25 @@ static int encode(struct ao *ao, double 
 
         if (ectx->options->rawts || ectx->options->copyts) {
             // real audio pts
-            frame->pts = floor(apts * ac->stream->codec->time_base.den / ac->stream->codec->time_base.num + 0.5);
+            frame->pts = floor(apts * ac->codec->time_base.den / ac->codec->time_base.num + 0.5);
         } else {
             // audio playback time
-            frame->pts = floor(realapts * ac->stream->codec->time_base.den / ac->stream->codec->time_base.num + 0.5);
+            frame->pts = floor(realapts * ac->codec->time_base.den / ac->codec->time_base.num + 0.5);
         }
 
-        int64_t frame_pts = av_rescale_q(frame->pts, ac->stream->codec->time_base, ac->worst_time_base);
+        int64_t frame_pts = av_rescale_q(frame->pts, ac->codec->time_base, ac->worst_time_base);
         if (ac->lastpts != AV_NOPTS_VALUE && frame_pts <= ac->lastpts) {
             // this indicates broken video
             // (video pts failing to increase fast enough to match audio)
             MP_WARN(ao, "audio frame pts went backwards (%d <- %d), autofixed\n",
                     (int)frame->pts, (int)ac->lastpts);
             frame_pts = ac->lastpts + 1;
-            frame->pts = av_rescale_q(frame_pts, ac->worst_time_base, ac->stream->codec->time_base);
+            frame->pts = av_rescale_q(frame_pts, ac->worst_time_base, ac->codec->time_base);
         }
         ac->lastpts = frame_pts;
 
-        frame->quality = ac->stream->codec->global_quality;
-        status = avcodec_encode_audio2(ac->stream->codec, &packet, frame, &gotpacket);
+        frame->quality = ac->codec->global_quality;
+        status = avcodec_encode_audio2(ac->codec, &packet, frame, &gotpacket);
 
         if (!status) {
             if (ac->savepts == AV_NOPTS_VALUE)
@@ -281,7 +281,7 @@ static int encode(struct ao *ao, double 
     }
     else
     {
-        status = avcodec_encode_audio2(ac->stream->codec, &packet, NULL, &gotpacket);
+        status = avcodec_encode_audio2(ac->codec, &packet, NULL, &gotpacket);
     }
 
     if(status) {
@@ -295,7 +295,7 @@ static int encode(struct ao *ao, double 
     MP_DBG(ao, "got pts %f (playback time: %f); out size: %d\n",
            apts, realapts, packet.size);
 
-    encode_lavc_write_stats(ao->encode_lavc_ctx, ac->stream);
+    encode_lavc_write_stats(ao->encode_lavc_ctx, ac->codec);
 
     packet.stream_index = ac->stream->index;
 
@@ -307,20 +307,20 @@ static int encode(struct ao *ao, double 
     }
 
     if (packet.pts != AV_NOPTS_VALUE)
-        packet.pts = av_rescale_q(packet.pts, ac->stream->codec->time_base,
+        packet.pts = av_rescale_q(packet.pts, ac->codec->time_base,
                 ac->stream->time_base);
 
     if (packet.dts != AV_NOPTS_VALUE)
-        packet.dts = av_rescale_q(packet.dts, ac->stream->codec->time_base,
+        packet.dts = av_rescale_q(packet.dts, ac->codec->time_base,
                 ac->stream->time_base);
 
     if(packet.duration > 0)
-        packet.duration = av_rescale_q(packet.duration, ac->stream->codec->time_base,
+        packet.duration = av_rescale_q(packet.duration, ac->codec->time_base,
                 ac->stream->time_base);
 
     ac->savepts = AV_NOPTS_VALUE;
 
-    if (encode_lavc_write_frame(ao->encode_lavc_ctx, &packet) < 0) {
+    if (encode_lavc_write_frame(ao->encode_lavc_ctx, ac->stream, &packet) < 0) {
         MP_ERR(ao, "error writing at %f %f/%f\n",
                realapts, (double) ac->stream->time_base.num,
                (double) ac->stream->time_base.den);
@@ -377,22 +377,22 @@ static int play(struct ao *ao, void **da
     }
 
     if (ac->worst_time_base.den == 0) {
-        //if (ac->stream->codec->time_base.num / ac->stream->codec->time_base.den >= ac->stream->time_base.num / ac->stream->time_base.den)
-        if (ac->stream->codec->time_base.num * (double) ac->stream->time_base.den >=
-                ac->stream->time_base.num * (double) ac->stream->codec->time_base.den) {
+        //if (ac->codec->time_base.num / ac->codec->time_base.den >= ac->stream->time_base.num / ac->stream->time_base.den)
+        if (ac->codec->time_base.num * (double) ac->stream->time_base.den >=
+                ac->stream->time_base.num * (double) ac->codec->time_base.den) {
             MP_VERBOSE(ao, "NOTE: using codec time base (%d/%d) for pts "
                        "adjustment; the stream base (%d/%d) is not worse.\n",
-                       (int)ac->stream->codec->time_base.num,
-                       (int)ac->stream->codec->time_base.den,
+                       (int)ac->codec->time_base.num,
+                       (int)ac->codec->time_base.den,
                        (int)ac->stream->time_base.num,
                        (int)ac->stream->time_base.den);
-            ac->worst_time_base = ac->stream->codec->time_base;
+            ac->worst_time_base = ac->codec->time_base;
             ac->worst_time_base_is_stream = 0;
         } else {
             MP_WARN(ao, "NOTE: not using codec time base (%d/%d) for pts "
                     "adjustment; the stream base (%d/%d) is worse.\n",
-                    (int)ac->stream->codec->time_base.num,
-                    (int)ac->stream->codec->time_base.den,
+                    (int)ac->codec->time_base.num,
+                    (int)ac->codec->time_base.den,
                     (int)ac->stream->time_base.num,
                     (int)ac->stream->time_base.den);
             ac->worst_time_base = ac->stream->time_base;
@@ -437,7 +437,7 @@ static int play(struct ao *ao, void **da
     }
 
     // Shift pts by the pts offset first.
-    outpts += encode_lavc_getoffset(ectx, ac->stream);
+    outpts += encode_lavc_getoffset(ectx, ac->codec);
 
     while (samples - bufpos >= ac->aframesize) {
         void *start[MP_NUM_CHANNELS] = {0};
