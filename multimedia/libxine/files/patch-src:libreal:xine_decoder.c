--- src/libreal/xine_decoder.c.orig	Mon Dec 15 07:13:24 2003
+++ src/libreal/xine_decoder.c	Mon Jan 12 00:04:26 2004
@@ -589,24 +589,15 @@
 
     /* try some auto-detection */
 
-    if (!stat ("/usr/local/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
+    if (!stat ("/usr/local/lib/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
       config->update_string (config, "codec.real_codecs_path", 
-			     "/usr/local/RealPlayer8/Codecs");
-    if (!stat ("/usr/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
+			     "/usr/local/lib/RealPlayer8/Codecs");
+    if (!stat ("/usr/local/lib/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s)) 
       config->update_string (config, "codec.real_codecs_path", 
-			     "/usr/RealPlayer8/Codecs");
-    if (!stat ("/usr/lib/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
+			     "/usr/local/lib/RealPlayer9/users/Real/Codecs");
+    if (!stat ("/usr/local/lib/win32/drv3.so.6.0", &s)) 
       config->update_string (config, "codec.real_codecs_path", 
-			     "/usr/lib/RealPlayer8/Codecs");
-    if (!stat ("/opt/RealPlayer8/Codecs/drv3.so.6.0", &s)) 
-      config->update_string (config, "codec.real_codecs_path", 
-			     "/opt/RealPlayer8/Codecs");
-    if (!stat ("/usr/lib/RealPlayer9/users/Real/Codecs/drv3.so.6.0", &s)) 
-      config->update_string (config, "codec.real_codecs_path", 
-			     "/usr/lib/RealPlayer9/users/Real/Codecs");
-    if (!stat ("/usr/lib/win32/drv3.so.6.0", &s)) 
-      config->update_string (config, "codec.real_codecs_path", 
-			     "/usr/lib/win32");
+			     "/usr/local/lib/win32");
   }
 
   lprintf ("real codec path : %s\n",  real_codec_path);
