--- ffmpeg.c.orig	Thu Oct 10 20:13:52 2002
+++ ffmpeg.c	Thu Oct 10 20:14:03 2002
@@ -36,6 +36,7 @@
 #include <ctype.h>
 
 
+#define INT64_C(x) x##LL
 #define MAXINT64 INT64_C(0x7fffffffffffffff)
 
 typedef struct {
@@ -146,7 +147,7 @@
 const char *audio_device = "none";
 #endif
 #ifndef CONFIG_VIDEO4LINUX
-const char *v4l_device = "none";
+const char *video_device = "none";
 #endif
 
 typedef struct AVOutputStream {
@@ -1601,7 +1602,7 @@
 
 void opt_video_device(const char *arg)
 {
-    v4l_device = strdup(arg);
+    video_device = strdup(arg);
 }
 
 void opt_audio_device(const char *arg)
@@ -2099,7 +2100,7 @@
         /* by now video grab has one stream */
         ic->streams[0]->r_frame_rate = ap->frame_rate;
         input_files[nb_input_files] = ic;
-        dump_format(ic, nb_input_files, v4l_device, 0);
+        dump_format(ic, nb_input_files, video_device, 0);
         nb_input_files++;
     }
     if (has_audio) {
