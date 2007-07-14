--- ./src/codec_encoder.c.orig	2007-07-14 20:50:06.000000000 +0400
+++ ./src/codec_encoder.c	2007-07-14 20:53:12.000000000 +0400
@@ -48,7 +48,8 @@
   	int i;
 	sample *d;
 
-	d = (sample *)c->data = (sample *)block_alloc(SAMPLES_PER_UNIT * BYTES_PER_SAMPLE);
+	c->data = (sample *)block_alloc(SAMPLES_PER_UNIT * BYTES_PER_SAMPLE);
+	d = (sample *)c->data;
 	c->data_len = SAMPLES_PER_UNIT * BYTES_PER_SAMPLE;
   	for (i=0; i < SAMPLES_PER_UNIT; i++) {
 		*d++ = htons(*data);
