--- ./talk/third_party/mediastreamer/msspeexdec.c.orig	Thu Mar 16 18:43:07 2006
+++ ./talk/third_party/mediastreamer/msspeexdec.c	Fri Apr 21 10:56:34 2006
@@ -171,6 +171,7 @@
 void ms_speex_dec_uninit_core(MSSpeexDec *obj)
 {
 	speex_decoder_destroy(obj->speex_state);
+	speex_bits_destroy(&obj->bits);
 	obj->initialized=0;
 }
 
