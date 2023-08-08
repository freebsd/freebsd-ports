--- src/mediaenc_ffmpeg.cpp.orig	2022-10-03 20:02:59 UTC
+++ src/mediaenc_ffmpeg.cpp
@@ -330,7 +330,9 @@ bool wxFfmpegMediaEncoder::addAudioStream(int codecId)
 		return false;
 	for (int i = 0; i < c->channels; i++) {
 		uint16_t *samples = (uint16_t*)m_audioFrame->data[i];
+		if (samples) {
 		memset(samples, 0, c->frame_size * av_get_bytes_per_sample(c->sample_fmt));
+		}
 	}
 
 	return true;
