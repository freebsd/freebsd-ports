--- gst-libs/ext/ffmpeg/libavformat/mov.c.orig	Fri Apr 30 20:41:45 2004
+++ gst-libs/ext/ffmpeg/libavformat/mov.c	Sun Jul 11 18:21:15 2004
@@ -998,6 +998,7 @@
             else if( st->codec.codec_tag == MKTAG( 'm', 'p', '4', 'a' ))
             {
                 /* Handle mp4 audio tag */
+                MOV_atom_t a = { format, url_ftell(pb), size - (20 + 20 + 8) };
                 get_be32(pb); /* version */
                 get_be32(pb);
                 st->codec.channels = get_be16(pb); /* channels */
@@ -1006,7 +1007,6 @@
                 st->codec.sample_rate = get_be16(pb); /* sample rate, not always correct */
                 get_be16(pb);
                 c->mp4=1;
-                MOV_atom_t a = { format, url_ftell(pb), size - (20 + 20 + 8) };
                 mov_read_default(c, pb, a);
                 /* Get correct sample rate from extradata */
                 if(st->codec.extradata_size) {
