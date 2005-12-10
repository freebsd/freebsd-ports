--- src/libreal/xine_decoder.c.orig	Thu Oct 27 23:58:56 2005
+++ src/libreal/xine_decoder.c	Sun Dec 11 02:52:23 2005
@@ -47,6 +47,14 @@
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
   video_decoder_class_t   decoder_class;
 
@@ -589,25 +597,13 @@
 
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
-  if (!stat ("/usr/lib/codecs/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib/codecs";
-  if (!stat ("/usr/lib/win32/drv3.so.6.0", &s)) 
-    default_real_codec_path = "/usr/lib/win32";
-  
+  if (!stat ("/usr/local/lib/RealPlayer8/Codecs/drv3.so.6.0", &s))
+    default_real_codec_path = "/usr/local/lib/RealPlayer8/Codecs";
+  if (!stat ("/usr/local/lib/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s))
+    default_real_codec_path = "/usr/local/lib/RealPlayer9/users/Real/Codecs";
+  if (!stat ("/usr/local/lib/win32/drv3.so.6.0", &s))
+    default_real_codec_path = "/usr/local/lib/win32";
+
   real_codec_path = config->register_string (config, "decoder.external.real_codecs_path", 
 					     default_real_codec_path,
 					     _("path to RealPlayer codecs"),
