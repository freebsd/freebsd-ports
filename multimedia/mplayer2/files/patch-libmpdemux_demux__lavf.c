--- libmpdemux/demux_lavf.c.orig	2013-07-09 16:33:16 UTC
+++ libmpdemux/demux_lavf.c
@@ -159,6 +159,7 @@ static int lavf_check_file(demuxer_t *de
     int probe_data_size = 0;
     int read_size = INITIAL_PROBE_SIZE;
     int score;
+    char mime[] = "";
 
     if (!demuxer->priv)
         demuxer->priv = calloc(sizeof(lavf_priv_t), 1);
@@ -203,6 +204,7 @@ static int lavf_check_file(demuxer_t *de
         avpd.buf_size = probe_data_size;
 
         score = 0;
+        avpd.mime_type = mime;
         priv->avif = av_probe_input_format2(&avpd, probe_data_size > 0, &score);
         read_size = FFMIN(2 * read_size, PROBE_BUF_SIZE - probe_data_size);
     } while ((demuxer->desc->type != DEMUXER_TYPE_LAVF_PREFERRED ||
@@ -383,9 +385,9 @@ static void handle_stream(demuxer_t *dem

         if (codec->codec_id == AV_CODEC_ID_RAWVIDEO) {
             switch (codec->pix_fmt) {
-            case PIX_FMT_RGB24:
+            case AV_PIX_FMT_RGB24:
                 codec->codec_tag = MKTAG(24, 'B', 'G', 'R');
-            case PIX_FMT_BGR24:
+            case AV_PIX_FMT_BGR24:
                 codec->codec_tag = MKTAG(24, 'R', 'G', 'B');
             }
             if (!codec->codec_tag)
