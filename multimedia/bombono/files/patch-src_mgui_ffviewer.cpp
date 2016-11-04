https://github.com/muravjov/bombono-dvd/commit/282273b8a581
https://github.com/muravjov/bombono-dvd/commit/2d72b907a81a
https://github.com/muravjov/bombono-dvd/commit/11f8b5a9cb2f

--- src/mgui/ffviewer.cpp.orig	2013-03-07 21:20:45 UTC
+++ src/mgui/ffviewer.cpp
@@ -48,6 +48,18 @@ C_LINKAGE_BEGIN
 C_LINKAGE_END
 #endif
 
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(57,05,00)
+C_LINKAGE_BEGIN
+#include <libavutil/imgutils.h>
+C_LINKAGE_END
+static int bmd_avpicture_get_size(enum AVPixelFormat pix_fmt, int width, int height)
+{
+    return av_image_get_buffer_size(pix_fmt, width, height, 1);
+}
+#else
+#define bmd_avpicture_get_size avpicture_get_size
+#endif
+
 // Прямой доступ к ff_codec_bmp_tags, в частности, закрыл, некий
 // Anton Khirnov, см. libavformat/libavformat.v (из него генерится скрипт
 // для опции --version-script=<script_file> линковщика ld)
@@ -406,7 +418,11 @@ static std::string CodecID2Str(CodecID codec_id)
 
 #else // CALC_FF_TAG
 
-static std::string CodecID2Str(CodecID codec_id)
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(55,00,00)
+//#define CodecID AVCodecID
+#endif
+
+static std::string CodecID2Str(AVCodecID codec_id)
 {
     return Int2Str(codec_id);
 }
@@ -617,6 +633,17 @@ FFInfo::~FFInfo()
     CloseInfo(*this);
 }
 
+static int bmd_avpicture_fill(AVFrame *picture, const uint8_t *ptr,
+                              AVPixelFormat pix_fmt, int width, int height)
+{
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(57,5,00)
+    return av_image_fill_arrays(picture->data, picture->linesize,
+                                ptr, pix_fmt, width, height, 1);
+#else
+    return avpicture_fill((AVPicture*)picture, ptr, pix_fmt, width, height);
+#endif
+}
+
 bool FFViewer::Open(const char* fname, std::string& err_str)
 {
     // * закрываем открытое ранее
@@ -635,11 +662,14 @@ bool FFViewer::Open(const char* fname, std::string& err_str)
         //     opt_default(); // обновление sws_opts по -sws_flags
         //     sws_flags = av_get_int(sws_opts, "sws_flags", NULL); // = sws_opts.flags    
         int sws_flags = SWS_BICUBIC;
+
+#if !(LIBSWSCALE_VERSION_INT >= AV_VERSION_INT(3,0,0))
         // при сборке с --enable-runtime-cpudetect (появилось после 0.5), который полюбили пакетировщики,
         // лучшая оптимизация выбирается на этапе выполнения, а не сборке; однако для 0.6 времени
         // maverick оно еще не доделано, см. http://ffmpeg.arrozcru.org/forum/viewtopic.php?f=1&t=1185
         // :KLUDGE: потому добавляем явно
         sws_flags |= SWS_CPU_CAPS_MMX|SWS_CPU_CAPS_MMX2;
+#endif
 
         // :TRICKY: почему-то ffmpeg'у "нравится" BGR24 и не нравиться RGB24 в плане использования
         // MMX (ускорения); цена по времени неизвестна,- используем только ради того, чтобы не было 
@@ -647,15 +677,27 @@ bool FFViewer::Open(const char* fname, std::string& err_str)
         // Другой вариант - PIX_FMT_RGB32, но там зависимый порядок байтов (в GdkPixbuf - нет) и
         // мы нацелены на RGB24
         // :TODO: с версии LIBSWSCALE_VERSION_INT >= 0.8.11 появился прямой yuv -> rgb24, поправить
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(54,17,00)
+        AVPixelFormat dst_pf = AV_PIX_FMT_BGR24; // AV_PIX_FMT_RGB24;
+#else
         PixelFormat dst_pf = PIX_FMT_BGR24; // PIX_FMT_RGB24;
+#endif
+
         rgbCnvCtx = sws_getContext(sz.x, sz.y, GetVideoCtx(*this)->pix_fmt, sz.x, sz.y,
             dst_pf, sws_flags, 0, 0, 0);
         ASSERT( rgbCnvCtx );
     
         Point dst_sz(sz);
-        rgbBuf = (uint8_t*)av_malloc(avpicture_get_size(dst_pf, dst_sz.x, dst_sz.y) * sizeof(uint8_t));
-        avcodec_get_frame_defaults(&rgbFrame); // не помешает
-        avpicture_fill((AVPicture*)&rgbFrame, rgbBuf, dst_pf, dst_sz.x, dst_sz.y);
+        rgbBuf = (uint8_t*)av_malloc(bmd_avpicture_get_size(dst_pf, dst_sz.x, dst_sz.y) * sizeof(uint8_t));
+
+        // не помешает
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(56,35,01)
+        av_frame_unref(&rgbFrame);
+#else
+        avcodec_get_frame_defaults(&rgbFrame);
+#endif
+
+        bmd_avpicture_fill(&rgbFrame, rgbBuf, dst_pf, dst_sz.x, dst_sz.y);
     }
     else
         // защита от неполных открытий
@@ -841,7 +883,11 @@ static bool DoDecode(FFViewer& ffv)
             
             DoVideoDecode(ffv, got_picture, &pkt);
         }
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(57,8,00)
+        av_packet_unref(&pkt);
+#else
         av_free_packet(&pkt);
+#endif
     }
     else if( av_res == (int)AVERROR_EOF ) // для mpegts также -EIO приходит
     {
@@ -1119,8 +1165,18 @@ static bool SeekSetTime(FFViewer& ffv, double time)
     {
         bool seek_ok = TimeSeek(ffv, start_time, time);
         if( !seek_ok && CanByteSeek(ffv.iCtx) )
+        {
             // тогда переходим в начало файла
-            seek_ok = DoSeek(ffv, ffv.iCtx->data_offset, true);
+#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(56,11,00)
+            // автор 9deaec782810d098bca11c9332fab2d2f4c5fb78 уверяет, что
+            // сокрытие AVFormatContext.internal в internal.h - это нормально
+            //int64_t data_offset = ffv.iCtx->internal->data_offset;
+            int64_t data_offset = 0;
+#else
+            int64_t data_offset = ffv.iCtx->data_offset;
+#endif
+            seek_ok = DoSeek(ffv, data_offset, true);
+        }
 
         // некоторое видео глючит в начале (Hellboy), из-за чего
         // последовательный доступ выполняется с перескоками -
