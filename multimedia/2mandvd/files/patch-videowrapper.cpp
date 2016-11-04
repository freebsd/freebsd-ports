--- videowrapper.cpp.orig	2013-07-30 11:46:19 UTC
+++ videowrapper.cpp
@@ -38,7 +38,7 @@ void videowrapper::delete_videowrapper()
 int videowrapper::load_video(QString filename)
 {
     // *** OUVERTURE DU FICHIER VIDEO ***
-    #ifdef avformat_open_input
+#if LIBAVFORMAT_VERSION_MAJOR >= 53
         if (avformat_open_input(&pFormatCtx,filename.toAscii().data(),NULL,NULL)!=0)
         {
     #else
@@ -91,7 +91,7 @@ int videowrapper::load_video(QString fil
 
     // *** OUVERTURE DU CODEC ***
 
-    #ifdef av_find_stream_info
+    #if 0
     if(avcodec_open(pCodecCtx, pCodec)<0)
     {
     #else
@@ -104,11 +104,11 @@ int videowrapper::load_video(QString fil
 
     img_convert_ctx = sws_getContext(pCodecCtx->width,
                     pCodecCtx->height, pCodecCtx->pix_fmt, pCodecCtx->width,
-                    pCodecCtx->height, PIX_FMT_RGB24, SWS_BICUBIC, NULL,
+                    pCodecCtx->height, AV_PIX_FMT_RGB24, SWS_BICUBIC, NULL,
                     NULL, NULL);
 
     // *** ON DETERMINE LA TAILLE DU BUFFER ***
-    numBytes=avpicture_get_size(PIX_FMT_RGB24, pCodecCtx->width,
+    numBytes=avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,
                                 pCodecCtx->height);
     buffer=(uint8_t *)av_malloc(numBytes*sizeof(uint8_t));
     old_frame = -1;
@@ -125,10 +125,10 @@ QImage videowrapper::read_frame(int64_t 
     if ( num_frame != old_frame )
     {
         // *** ALLOCATE VIDEO FRAME ***
-        pFrameRGB=avcodec_alloc_frame();
-        pFrame=avcodec_alloc_frame();
+        pFrameRGB=av_frame_alloc();
+        pFrame=av_frame_alloc();
 
-        avpicture_fill((AVPicture *)pFrameRGB, buffer, PIX_FMT_RGB24,
+        avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24,
                         pCodecCtx->width, pCodecCtx->height);
         av_seek_frame(pFormatCtx,videoStream,0, AVSEEK_FLAG_FRAME);
         compte_frame = -1;
