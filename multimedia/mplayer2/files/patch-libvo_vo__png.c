--- libvo/vo_png.c.orig	2013-07-09 16:33:16 UTC
+++ libvo/vo_png.c
@@ -87,11 +87,12 @@ config(uint32_t width, uint32_t height,


 static uint32_t draw_image(mp_image_t* mpi){
-    AVFrame pic;
+    AVFrame *pic;
     int buffersize;
-    int res;
+    int res, got_pkt;
     char buf[100];
     FILE *outfile;
+    AVPacket pkt;

     // if -dr or -slices then do nothing:
     if(mpi->flags&(MP_IMGFLAG_DIRECT|MP_IMGFLAG_DRAW_CALLBACK)) return VO_TRUE;
@@ -103,24 +104,29 @@ static uint32_t draw_image(mp_image_t* m
         return 1;
     }

-    pic.data[0] = mpi->planes[0];
-    pic.linesize[0] = mpi->stride[0];
+    pic = av_frame_alloc();
+    pic->data[0] = mpi->planes[0];
+    pic->linesize[0] = mpi->stride[0];
     buffersize = mpi->w * mpi->h * 8;
     if (outbuffer_size < buffersize) {
         av_freep(&outbuffer);
         outbuffer = av_malloc(buffersize);
         outbuffer_size = buffersize;
     }
-    res = avcodec_encode_video(avctx, outbuffer, outbuffer_size, &pic);
+    av_init_packet(&pkt);
+    pkt.data = outbuffer;
+    pkt.size = outbuffer_size;
+    res = avcodec_encode_video2(avctx, &pkt, pic, &got_pkt);
+    av_frame_free(&pic);

-    if(res < 0){
- 	    mp_msg(MSGT_VO,MSGL_WARN, "[VO_PNG] Error in create_png.\n");
-            fclose(outfile);
-	    return 1;
+    if (res < 0 || !got_pkt) {
+         mp_msg(MSGT_VO,MSGL_WARN, "[VO_PNG] Error in create_png.\n");
+    } else {
+         fwrite(outbuffer, pkt.size, 1, outfile);
     }

-    fwrite(outbuffer, res, 1, outfile);
     fclose(outfile);
+    av_free_packet(&pkt);

     return VO_TRUE;
 }
