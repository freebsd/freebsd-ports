--- ./talk/third_party/mediastreamer/msspeexenc.c.orig	Thu Mar 16 18:43:07 2006
+++ ./talk/third_party/mediastreamer/msspeexenc.c	Fri Apr 21 10:56:34 2006
@@ -157,6 +157,7 @@
 {
 	if (obj->initialized){
 		speex_encoder_destroy(obj->speex_state);
+		speex_bits_destroy(&obj->bits);
 		obj->initialized=0;
 	}
 }
