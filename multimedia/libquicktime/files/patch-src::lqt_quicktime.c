--- src/lqt_quicktime.c.orig	Wed Mar  2 03:01:19 2005
+++ src/lqt_quicktime.c	Wed Mar  2 03:01:34 2005
@@ -1018,7 +1018,6 @@
         return result;
 }
 
-#if 0 /* This function is obsolete as it makes no sense for compressed codecs */
 long quicktime_read_audio(quicktime_t *file, char *audio_buffer, long samples, int track)
 {
 	int64_t chunk_sample, chunk;
@@ -1058,7 +1057,6 @@
 	if(result) return 0;
 	return total_bytes;
 }
-#endif
 
 int quicktime_read_chunk(quicktime_t *file, char *output, int track, int64_t chunk, int64_t byte_start, int64_t byte_len)
 {
