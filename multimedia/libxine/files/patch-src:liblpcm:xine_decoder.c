--- src/liblpcm/xine_decoder.c.orig	Fri Nov 30 20:46:02 2001
+++ src/liblpcm/xine_decoder.c	Fri Nov 30 20:46:23 2001
@@ -117,7 +117,7 @@
 
   stream_be = ( buf->type == BUF_AUDIO_LPCM_BE );
   if (stream_be != this->cpu_be)
-    swab (audio_buffer->mem, sample_buffer, buf->size);
+    swab (sample_buffer, audio_buffer->mem, buf->size);
   else
     memcpy (audio_buffer->mem, sample_buffer, buf->size);
 
