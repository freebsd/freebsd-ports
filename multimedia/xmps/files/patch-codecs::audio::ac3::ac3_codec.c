
$FreeBSD$

--- codecs/audio/ac3/ac3_codec.c.orig	Mon Nov 20 21:41:18 2000
+++ codecs/audio/ac3/ac3_codec.c	Sun Feb  4 23:18:46 2001
@@ -60,7 +60,7 @@
 
 } ac3_t;
 
-int error;
+int ac3_error;
 
 /*
  * get_audio_codec_info : MANDATORY
@@ -96,7 +96,7 @@
   ((ac3_t *) audio_decoder->data)->smixlev_lut[2] = 0.0;
   ((ac3_t *) audio_decoder->data)->smixlev_lut[3] = 0.500;
   
-  error = 0;
+  ac3_error = 0;
 
   return audio_decoder;
 }
@@ -208,7 +208,7 @@
     
     exponent_unpack(&data->bsi, &data->audblk);
     
-    if(error)
+    if(ac3_error)
       goto error;
     
     // Figure out how many bits per mantissa 
@@ -220,7 +220,7 @@
     
     coeff_unpack (&data->bsi, &data->audblk, data->samples);
 
-    if(error)
+    if(ac3_error)
       goto error;
         
     if(data->bsi.acmod == 0x2)
@@ -242,7 +242,7 @@
   memset(data->s16_samples, 0, 256*2*2*6);
   ring_write((char *) data->s16_samples, 256*2*2*6);
 
-  error = 0;
+  ac3_error = 0;
 
 }
 
