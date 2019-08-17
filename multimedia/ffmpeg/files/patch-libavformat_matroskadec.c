https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/299e0dff1fbc

--- libavformat/matroskadec.c.orig	2019-08-05 20:52:21 UTC
+++ libavformat/matroskadec.c
@@ -757,7 +757,7 @@ static int matroska_reset_status(MatroskaDemuxContext 
                                  uint32_t id, int64_t position)
 {
     if (position >= 0) {
-        int err = avio_seek(matroska->ctx->pb, position, SEEK_SET);
+        int64_t err = avio_seek(matroska->ctx->pb, position, SEEK_SET);
         if (err < 0)
             return err;
     }
