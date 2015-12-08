--- src/mgui/ffviewer.cpp.orig	2013-03-07 21:20:45 UTC
+++ src/mgui/ffviewer.cpp
@@ -406,7 +406,7 @@ static std::string CodecID2Str(CodecID c
 
 #else // CALC_FF_TAG
 
-static std::string CodecID2Str(CodecID codec_id)
+static std::string CodecID2Str(AVCodecID codec_id)
 {
     return Int2Str(codec_id);
 }
@@ -1119,8 +1119,10 @@ static bool SeekSetTime(FFViewer& ffv, d
     {
         bool seek_ok = TimeSeek(ffv, start_time, time);
         if( !seek_ok && CanByteSeek(ffv.iCtx) )
-            // тогда переходим в начало файла
-            seek_ok = DoSeek(ffv, ffv.iCtx->data_offset, true);
+            // then seek to the file's start; since data_offset is private
+            // now, if we seek to 0 and there is a data_offset our seek will
+            // be rounded to the minimum possible, i.e. data_offset.
+            seek_ok = DoSeek(ffv, /* ffv.iCtx->data_offset */ 0, true);
 
         // некоторое видео глючит в начале (Hellboy), из-за чего
         // последовательный доступ выполняется с перескоками -
