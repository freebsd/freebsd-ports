--- src/libreal/audio_decoder.c.orig	Thu Dec 16 22:59:10 2004
+++ src/libreal/audio_decoder.c	Thu Dec 30 08:55:14 2004
@@ -48,6 +48,14 @@
 #include "buffer.h"
 #include "xineutils.h"
 
+#if defined(__FreeBSD__)
+void ___brk_addr(void) {exit(0);}
+void __ctype_b(void) {exit(0);}
+char **__environ={NULL};
+#undef stderr
+FILE *stderr=NULL;
+#endif
+
 typedef struct {
   audio_decoder_class_t   decoder_class;
 
@@ -709,22 +717,12 @@
 
   /* try some auto-detection */
 
-  if (!stat ("/usr/local/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/local/RealPlayer8/Codecs";
-  if (!stat ("/usr/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/RealPlayer8/Codecs";
-  if (!stat ("/usr/lib/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib/RealPlayer8/Codecs";
-  if (!stat ("/opt/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/opt/RealPlayer8/Codecs";
-  if (!stat ("/usr/lib/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib/RealPlayer9/users/Real/Codecs";
-  if (!stat ("/usr/lib64/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib64/RealPlayer8/Codecs";
-  if (!stat ("/usr/lib64/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib64/RealPlayer9/users/Real/Codecs";
-  if (!stat ("/usr/lib/win32/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib/win32";
+  if (!stat ("/usr/local/lib/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
+    default_real_codec_path = "/usr/local/lib/RealPlayer8/Codecs";
+  if (!stat ("/usr/local/lib/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s)) 
+    default_real_codec_path = "/usr/local/lib/RealPlayer9/users/Real/Codecs";
+  if (!stat ("/usr/local/lib/win32/drv3.so.6.0", &s)) 
+    default_real_codec_path = "/usr/local/lib/win32";
   
   real_codec_path = config->register_string (config, "decoder.external.real_codecs_path", 
 					     default_real_codec_path,
