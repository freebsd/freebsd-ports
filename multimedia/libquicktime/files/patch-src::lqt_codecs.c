--- src/lqt_codecs.c.orig	Wed Mar  2 03:10:55 2005
+++ src/lqt_codecs.c	Wed Mar  2 03:11:08 2005
@@ -787,7 +787,6 @@
 	((quicktime_codec_t*)file->vtracks[track].codec)->flush(file, track);
 }
 
-#if 0
 int64_t quicktime_samples_to_bytes(quicktime_trak_t *track, long samples)
 {
 	char *compressor = track->mdia.minf.stbl.stsd.table[0].format;
@@ -802,7 +801,6 @@
 /* Default use the sample size specification for TWOS and RAW */
 	return samples * channels * track->mdia.minf.stbl.stsd.table[0].sample_size / 8;
 }
-#endif
 int quicktime_codecs_flush(quicktime_t *file)
 {
 	int result = 0;
