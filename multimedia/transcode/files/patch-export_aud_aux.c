--- export/aud_aux.c.orig	2007-07-31 10:11:13.000000000 -0400
+++ export/aud_aux.c	2007-07-31 10:10:10.000000000 -0400
@@ -361,8 +361,7 @@
 
     pthread_mutex_lock(&init_avcodec_lock);
     avcodec_init();
-    register_avcodec(&ac3_encoder);
-    register_avcodec(&mp2_encoder);
+    avcodec_register_all();
     pthread_mutex_unlock(&init_avcodec_lock);
 
     switch (o_codec) {
