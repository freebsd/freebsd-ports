--- Input/vorbis/vorbis.c.orig	Wed Dec 24 09:00:39 2003
+++ Input/vorbis/vorbis.c	Wed Dec 24 09:00:52 2003
@@ -134,6 +134,7 @@
 	FILE *stream;
 	OggVorbis_File vfile; /* avoid thread interaction */
 	char *ext;
+	gint result;
 
 
 	/* is this our http resource? */
@@ -161,7 +162,6 @@
 	memset(&vfile, 0, sizeof(vfile));
 	pthread_mutex_lock(&vf_mutex);
 
-	gint result;
 	result = ov_test(stream, &vfile, NULL, 0);
 
 	switch (result) {
