media_object.cpp:908:60: error: use of undeclared identifier 'CODEC_CAP_DR1'
            if (lowres || (codec && (codec->capabilities & CODEC_CAP_DR1)))
                                                           ^
media_object.cpp:909:37: error: use of undeclared identifier 'CODEC_FLAG_EMU_EDGE'
                codec_ctx->flags |= CODEC_FLAG_EMU_EDGE;
                                    ^

--- src/media_object.cpp.orig	2016-11-30 19:18:54 UTC
+++ src/media_object.cpp
@@ -905,8 +905,10 @@ void media_object::open(const std::string &url, const 
 #ifdef FF_API_LOWRES
             lowres = codec_ctx->lowres;
 #endif
+#ifdef FF_API_EMU_EDGE
             if (lowres || (codec && (codec->capabilities & CODEC_CAP_DR1)))
                 codec_ctx->flags |= CODEC_FLAG_EMU_EDGE;
+#endif
         }
         // Find and open the codec. AV_CODEC_ID_TEXT is a special case: it has no decoder since it is unencoded raw data.
         if (codec_ctx->codec_id != AV_CODEC_ID_TEXT && (!codec || (e = avcodec_open2(codec_ctx, codec, NULL)) < 0))
