--- ffmpeg.c.orig	Wed Jan  1 20:56:06 2003
+++ ffmpeg.c	Wed Jan  1 20:56:41 2003
@@ -35,6 +35,7 @@
 #define INFINITY HUGE_VAL
 #endif
 
+#define INT64_C(x) x##LL
 #define MAXINT64 INT64_C(0x7fffffffffffffff)
 
 typedef struct {
@@ -158,7 +159,7 @@
 const char *audio_device = "none";
 #endif
 #ifndef CONFIG_VIDEO4LINUX
-const char *v4l_device = "none";
+const char *video_device = "none";
 #endif
 
 typedef struct AVOutputStream {
@@ -1842,7 +1843,7 @@
 
 void opt_video_device(const char *arg)
 {
-    v4l_device = strdup(arg);
+    video_device = strdup(arg);
 }
 
 void opt_audio_device(const char *arg)
@@ -2428,7 +2429,7 @@
         /* by now video grab has one stream */
         ic->streams[0]->r_frame_rate = ap->frame_rate;
         input_files[nb_input_files] = ic;
-        dump_format(ic, nb_input_files, v4l_device, 0);
+        dump_format(ic, nb_input_files, video_device, 0);
         nb_input_files++;
     }
     if (has_audio) {
