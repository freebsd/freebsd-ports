--- ext/ffmpeg/gstffmpegdec.c~
+++ ext/ffmpeg/gstffmpegdec.c
@@ -3042,9 +3042,6 @@ gst_ffmpegdec_register (GstPlugin * plug
       case CODEC_ID_SIPR:
         rank = GST_RANK_SECONDARY;
         break;
-      case CODEC_ID_MP3:
-        rank = GST_RANK_NONE;
-        break;
         /* TEMPORARILY DISABLING AC3/EAC3/DTS for 0.10.12 release
          * due to downmixing failure.
          * See Bug #608892 for more details */
