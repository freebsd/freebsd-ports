--- libmpcodecs/vf_lavc.c.orig	2013-07-09 16:33:16 UTC
+++ libmpcodecs/vf_lavc.c
@@ -83,6 +83,8 @@ static int put_image(struct vf_instance
     mp_image_t* dmpi;
     int out_size;
     AVFrame *pic= vf->priv->pic;
+    int ret, got_pkt;
+    AVPacket pkt;

     pic->data[0]=mpi->planes[0];
     pic->data[1]=mpi->planes[1];
@@ -91,10 +93,14 @@ static int put_image(struct vf_instance
     pic->linesize[1]=mpi->stride[1];
     pic->linesize[2]=mpi->stride[2];

-    out_size = avcodec_encode_video(&lavc_venc_context,
-	vf->priv->outbuf, vf->priv->outbuf_size, pic);
+    av_init_packet(&pkt);
+    pkt.data = vf->priv->outbuf;
+    pkt.size = vf->priv->outbuf_size;
+    ret = avcodec_encode_video2(&lavc_venc_context, &pkt, pic, &got_pkt);

-    if(out_size<=0) return 1;
+    if(ret<=0) return 1;
+    if(!got_pkt) return 1;
+    out_size = pkt.size;

     dmpi=vf_get_image(vf->next,IMGFMT_MPEGPES,
 	MP_IMGTYPE_EXPORT, 0,
@@ -139,7 +145,7 @@ static int vf_open(vf_instance_t *vf, ch
     }

     vf->priv->context=avcodec_alloc_context3(vf->priv->codec);
-    vf->priv->pic = avcodec_alloc_frame();
+    vf->priv->pic = av_frame_alloc();

     // TODO: parse args ->
     if(args) sscanf(args, "%d:%f", &p_quality, &p_fps);
@@ -156,7 +162,7 @@ static int vf_open(vf_instance_t *vf, ch
     lavc_venc_context.time_base.num = 1000*1001;
     lavc_venc_context.time_base.den = (p_fps<1.0) ? 1000*1001*25 : (p_fps * lavc_venc_context.time_base.num);
     lavc_venc_context.gop_size = 0; // I-only
-    lavc_venc_context.pix_fmt= PIX_FMT_YUV420P;
+    lavc_venc_context.pix_fmt= AV_PIX_FMT_YUV420P;

     return 1;
 }
