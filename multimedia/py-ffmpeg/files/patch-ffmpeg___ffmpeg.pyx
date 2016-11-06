--- ffmpeg/_ffmpeg.pyx.orig	2013-10-28 16:04:02 UTC
+++ ffmpeg/_ffmpeg.pyx
@@ -518,11 +518,11 @@ cdef int audio_decode_frame(VideoState *
             got_frame = 0
 
             if frame == NULL:
-                frame = avcodec_alloc_frame()
+                frame = av_frame_alloc()
                 if frame == NULL:
                     return -1
             else:
-                avcodec_get_frame_defaults(frame)
+                av_frame_unref(frame)
 
             len1 = avcodec_decode_audio4(vs.audio_st.codec,
                     frame, &got_frame, pkt)
@@ -784,7 +784,7 @@ cdef void alloc_picture(void *userdata) 
 
     vp.ff_data_size = avpicture_get_size(PF_RGB24, vp.width, vp.height)
     vp.ff_data = <unsigned char *>av_malloc(vp.ff_data_size * sizeof(unsigned char))
-    vp.bmp = avcodec_alloc_frame()
+    vp.bmp = av_frame_alloc()
     avpicture_fill(<AVPicture *>vp.bmp, vp.ff_data, PF_RGB24,
             vp.width, vp.height)
 
@@ -886,19 +886,6 @@ cdef double synchronize_video(VideoState
     return pts
 
 
-cdef int our_get_buffer(AVCodecContext *c, AVFrame *pic) nogil:
-    cdef int ret = avcodec_default_get_buffer(c, pic)
-    cdef uint64_t *pts = <uint64_t*>av_malloc(sizeof(uint64_t))
-    memcpy(pts, &global_video_pkt_pts, sizeof(uint64_t))
-    pic.opaque = pts
-    return ret
-
-
-cdef void our_release_buffer(AVCodecContext *c, AVFrame *pic) nogil:
-    if pic != NULL: av_freep(&pic.opaque)
-    avcodec_default_release_buffer(c, pic)
-
-
 cdef int video_thread(void *arg) nogil:
     cdef VideoState *vs = <VideoState *>arg
     cdef AVPacket pkt1, *packet = &pkt1
@@ -906,7 +893,7 @@ cdef int video_thread(void *arg) nogil:
     cdef AVFrame *pFrame
     cdef double pts, ptst = 0
 
-    pFrame = avcodec_alloc_frame()
+    pFrame = av_frame_alloc()
 
     while True:
         if packet_queue_get(&vs.videoq, packet, 1) < 0:
@@ -1038,8 +1025,6 @@ cdef int stream_component_open(VideoStat
 
         packet_queue_init(&vs.videoq)
         vs.video_tid = SDL_CreateThread(video_thread, vs)
-        codecCtx.get_buffer = our_get_buffer
-        codecCtx.release_buffer = our_release_buffer
 
     else:
         pass
