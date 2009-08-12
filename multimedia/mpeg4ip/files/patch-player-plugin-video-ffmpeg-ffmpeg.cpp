--- player/plugin/video/ffmpeg/ffmpeg.cpp	2007-07-02 22:26:03.000000000 +0200
+++ player/plugin/video/ffmpeg/ffmpeg.cpp	2008-10-10 23:01:19.519476374 +0200
@@ -585,10 +585,16 @@ static int ffmpeg_decode (codec_data_t *
 	from.data[ix] = ffmpeg->m_picture->data[ix];
 	from.linesize[ix] = ffmpeg->m_picture->linesize[ix];
       }
-      
-      img_convert(&to, PIX_FMT_YUV420P,
-		  &from, ffmpeg->m_c->pix_fmt,
-		  ffmpeg->m_c->width, ffmpeg->m_c->height);
+#ifdef HAVE_FFMPEG_INSTALLED
+      SwsContext *pSWSCtx;
+      pSWSCtx = sws_getContext(ffmpeg->m_c->width, ffmpeg->m_c->height,
+			       ffmpeg->m_c->pix_fmt,
+			       ffmpeg->m_c->width, ffmpeg->m_c->height,
+			       PIX_FMT_YUV420P, SWS_BICUBIC, 0, 0, 0);
+      sws_scale(pSWSCtx, from.data, from.linesize, 0, ffmpeg->m_c->height,
+		to.data, to.linesize);
+      sws_freeContext(pSWSCtx);
+#endif
       ffmpeg->m_vft->video_filled_buffer(ffmpeg->m_ifptr,
 					 ffmpeg->have_cached_ts ?
 					 ffmpeg->cached_ts : ts);
