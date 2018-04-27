Upstream fix from 4.1.* causes too many merge conflicts.
https://github.com/Motion-Project/motion/commit/b5c3a73cc62e
https://github.com/Motion-Project/motion/commit/9b93a417e37e

--- ffmpeg.c.orig	2016-10-25 01:39:24 UTC
+++ ffmpeg.c
@@ -439,7 +439,7 @@ struct ffmpeg *ffmpeg_open(const char *ffmpeg_video_co
         /* The selection of 8000 in the else is a subjective number based upon viewing output files */
         if (vbr > 0){
             ffmpeg->vbr =(int)(((100-vbr)*(100-vbr)*(100-vbr) * 8000) / 1000000) + 1;
-            c->flags |= CODEC_FLAG_QSCALE;
+            c->flags |= AV_CODEC_FLAG_QSCALE;
             c->global_quality=ffmpeg->vbr;
         }
     }
@@ -447,7 +447,7 @@ struct ffmpeg *ffmpeg_open(const char *ffmpeg_video_co
     MOTION_LOG(INF, TYPE_ENCODER, NO_ERRNO, "%s vbr/crf for codec: %d", ffmpeg->vbr);
 
     if (strcmp(ffmpeg_video_codec, "ffv1") == 0) c->strict_std_compliance = -2;
-    c->flags |= CODEC_FLAG_GLOBAL_HEADER;
+    c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
 
     retcd = avcodec_open2(c, codec, &opts);
     if (retcd < 0) {
@@ -489,7 +489,10 @@ struct ffmpeg *ffmpeg_open(const char *ffmpeg_video_co
     }
 
     ffmpeg->video_outbuf = NULL;
-    if (!(ffmpeg->oc->oformat->flags & AVFMT_RAWPICTURE)) {
+#ifdef AVFMT_RAWPICTURE
+    if (!(ffmpeg->oc->oformat->flags & AVFMT_RAWPICTURE))
+#endif
+    {
         ffmpeg->video_outbuf_size = ffmpeg->c->width * 512;
         ffmpeg->video_outbuf = mymalloc(ffmpeg->video_outbuf_size);
     }
@@ -705,12 +708,15 @@ int ffmpeg_put_frame(struct ffmpeg *ffmpeg, AVFrame *p
     gettimeofday(&tv1, NULL);
 
     av_init_packet(&pkt); /* Init static structure. */
+#ifdef AVFMT_RAWPICTURE
     if (ffmpeg->oc->oformat->flags & AVFMT_RAWPICTURE) {
         pkt.stream_index = ffmpeg->video_st->index;
         pkt.flags |= AV_PKT_FLAG_KEY;
         pkt.data = (uint8_t *)pic;
         pkt.size = sizeof(AVPicture);
-    } else {
+    } else
+#endif
+    {
         pkt.data = NULL;
         pkt.size = 0;
         retcd = avcodec_encode_video2(AVSTREAM_CODEC_PTR(ffmpeg->video_st),
