--- Input/vorbis/vorbis.c.orig	Sat Feb  7 19:26:13 2004
+++ Input/vorbis/vorbis.c	Sat Feb  7 19:32:10 2004
@@ -521,12 +521,12 @@
 
 static void vorbis_play(char *filename)
 {
+	 pthread_attr_t pta;
     vorbis_playing = 1;
     vorbis_bytes_streamed = 0;
     vorbis_eos = 0;
     output_error = FALSE;
 
-    pthread_attr_t pta;
     (void) pthread_attr_init(&pta);
     (void) pthread_attr_setschedpolicy(&pta, PTHREAD_INHERIT_SCHED);
     (void) pthread_attr_setscope(&pta, PTHREAD_SCOPE_SYSTEM);
