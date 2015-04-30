--- libmpcodecs/vd_theora.c.orig	2015-03-25 00:52:12.768575000 +0100
+++ libmpcodecs/vd_theora.c	2015-03-25 01:17:34.162174000 +0100
@@ -39,22 +39,23 @@
 
 LIBVD_EXTERN(theora)
 
-#include <theora/theora.h>
+#include <theora/theoradec.h>
 
 #define THEORA_NUM_HEADER_PACKETS 3
 
 typedef struct theora_struct_st {
-    theora_state st;
-    theora_comment cc;
-    theora_info inf;
+    th_setup_info *tsi;
+    th_dec_ctx    *tctx;
+    th_comment     tc;
+    th_info        ti;	
 } theora_struct_t;
 
 /** Convert Theora pixelformat to the corresponding IMGFMT_ */
-static uint32_t theora_pixelformat2imgfmt(theora_pixelformat fmt){
+static uint32_t theora_pixelformat2imgfmt(th_pixel_fmt fmt){
     switch(fmt) {
-       case OC_PF_420: return IMGFMT_YV12;
-       case OC_PF_422: return IMGFMT_422P;
-       case OC_PF_444: return IMGFMT_444P;
+       case TH_PF_420: return IMGFMT_YV12;
+       case TH_PF_422: return IMGFMT_422P;
+       case TH_PF_444: return IMGFMT_444P;
     }
     return 0;
 }
@@ -64,7 +65,7 @@
     theora_struct_t *context = sh->context;
     switch(cmd) {
     case VDCTRL_QUERY_FORMAT:
-        if (*(int*)arg == theora_pixelformat2imgfmt(context->inf.pixelformat))
+        if (*(int*)arg == theora_pixelformat2imgfmt(context->ti.pixel_fmt))
 	    return CONTROL_TRUE;
 	return CONTROL_FALSE;
     }
@@ -88,8 +89,10 @@
     if (!context)
         goto err_out;
 
-    theora_info_init(&context->inf);
-    theora_comment_init(&context->cc);
+    th_info_init(&context->ti);
+    th_comment_init(&context->tc);
+    context->tsi = NULL;
+	
 
     /* Read all header packets, pass them to theora_decode_header. */
     for (i = 0; i < THEORA_NUM_HEADER_PACKETS; i++)
@@ -109,7 +112,7 @@
             op.b_o_s = 1;
         }
 
-        if ( (errorCode = theora_decode_header (&context->inf, &context->cc, &op)) )
+        if ( (errorCode = th_decode_headerin (&context->ti, &context->tc, &context->tsi, &op)) < 0)
         {
             mp_msg(MSGT_DECVIDEO, MSGL_ERR, "Broken Theora header; errorCode=%i!\n", errorCode);
             goto err_out;
@@ -117,23 +120,25 @@
     }
 
     /* now init codec */
-    errorCode = theora_decode_init (&context->st, &context->inf);
-    if (errorCode)
+    context->tctx = th_decode_alloc (&context->ti, &context->tsi);
+    if (!context->tctx)
     {
-        mp_msg(MSGT_DECVIDEO,MSGL_ERR,"Theora decode init failed: %i \n", errorCode);
+        mp_msg(MSGT_DECVIDEO,MSGL_ERR,"Theora decode init failed\n");
         goto err_out;
     }
+    /* free memory used for decoder setup information */
+    th_setup_free(context->tsi);		
 
-    if(sh->aspect==0.0 && context->inf.aspect_denominator!=0)
+    if(sh->aspect==0.0 && context->ti.aspect_denominator!=0)
     {
-       sh->aspect = ((double)context->inf.aspect_numerator * context->inf.width)/
-          ((double)context->inf.aspect_denominator * context->inf.height);
+       sh->aspect = ((double)context->ti.aspect_numerator * context->ti.frame_width)/
+          ((double)context->ti.aspect_denominator * context->ti.frame_height);
     }
 
     mp_msg(MSGT_DECVIDEO,MSGL_V,"INFO: Theora video init ok!\n");
-    mp_msg(MSGT_DECVIDEO,MSGL_INFO,"Frame: %dx%d, Picture %dx%d, Offset [%d,%d]\n", context->inf.width, context->inf.height, context->inf.frame_width, context->inf.frame_height, context->inf.offset_x, context->inf.offset_y);
+    mp_msg(MSGT_DECVIDEO,MSGL_INFO,"Frame: %dx%d, Picture %dx%d, Offset [%d,%d]\n", context->ti.frame_width, context->ti.frame_height, context->ti.pic_width, context->ti.pic_height, context->ti.pic_x, context->ti.pic_y);
 
-    return mpcodecs_config_vo (sh,context->inf.width,context->inf.height,theora_pixelformat2imgfmt(context->inf.pixelformat));
+    return mpcodecs_config_vo (sh,context->ti.frame_width,context->ti.frame_height,theora_pixelformat2imgfmt(context->ti.pixel_fmt));
 
 err_out:
     free(context);
@@ -150,9 +155,9 @@
 
    if (context)
    {
-      theora_info_clear(&context->inf);
-      theora_comment_clear(&context->cc);
-      theora_clear (&context->st);
+      th_info_clear(&context->ti);
+      th_comment_clear(&context->tc);
+      th_decode_free (context->tctx);
       free (context);
    }
 }
@@ -165,7 +170,7 @@
    theora_struct_t *context = sh->context;
    int errorCode = 0;
    ogg_packet op;
-   yuv_buffer yuv;
+   th_ycbcr_buffer ycbcrbuf;
    mp_image_t* mpi;
 
    // no delayed frames
@@ -177,31 +182,31 @@
    op.packet = data;
    op.granulepos = -1;
 
-   errorCode = theora_decode_packetin (&context->st, &op);
-   if (errorCode)
+   errorCode = th_decode_packetin (context->tctx, &op, NULL);
+   if (errorCode < 0)
    {
       mp_msg(MSGT_DECVIDEO,MSGL_ERR,"Theora decode packetin failed: %i \n",
 	     errorCode);
       return NULL;
    }
 
-   errorCode = theora_decode_YUVout (&context->st, &yuv);
-   if (errorCode)
+   errorCode = th_decode_ycbcr_out (context->tctx, ycbcrbuf);
+   if (errorCode < 0)
    {
       mp_msg(MSGT_DECVIDEO,MSGL_ERR,"Theora decode YUVout failed: %i \n",
 	     errorCode);
       return NULL;
    }
 
-    mpi = mpcodecs_get_image(sh, MP_IMGTYPE_EXPORT, 0, yuv.y_width, yuv.y_height);
+    mpi = mpcodecs_get_image(sh, MP_IMGTYPE_EXPORT, 0, ycbcrbuf[0].width, ycbcrbuf[0].height);
     if(!mpi) return NULL;
 
-    mpi->planes[0]=yuv.y;
-    mpi->stride[0]=yuv.y_stride;
-    mpi->planes[1]=yuv.u;
-    mpi->stride[1]=yuv.uv_stride;
-    mpi->planes[2]=yuv.v;
-    mpi->stride[2]=yuv.uv_stride;
+    mpi->planes[0]=ycbcrbuf[0].data;
+    mpi->stride[0]=ycbcrbuf[0].stride;
+    mpi->planes[1]=ycbcrbuf[1].data;
+    mpi->stride[1]=ycbcrbuf[1].stride;
+    mpi->planes[2]=ycbcrbuf[2].data;
+    mpi->stride[2]=ycbcrbuf[2].stride;
 
     return mpi;
 }
