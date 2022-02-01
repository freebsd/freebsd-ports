--- media/libcubeb/src/cubeb_oss.c.orig	2021-12-18 20:36:16 UTC
+++ media/libcubeb/src/cubeb_oss.c
@@ -97,6 +97,7 @@ struct oss_stream {
   int fd;
   void * buf;
   unsigned int bufframes;
+  unsigned int maxframes;
 
   struct stream_info {
     int channels;
@@ -822,9 +823,9 @@ retry:
       pfds[0].fd = s->play.fd;
       pfds[1].fd = -1;
       goto retry;
-    } else if (tnfr > (long)s->play.bufframes) {
+    } else if (tnfr > (long)s->play.maxframes) {
       /* too many frames available - limit */
-      tnfr = (long)s->play.bufframes;
+      tnfr = (long)s->play.maxframes;
     }
     if (nfr > tnfr) {
       nfr = tnfr;
@@ -840,9 +841,9 @@ retry:
       pfds[0].fd = -1;
       pfds[1].fd = s->record.fd;
       goto retry;
-    } else if (tnfr > (long)s->record.bufframes) {
+    } else if (tnfr > (long)s->record.maxframes) {
       /* too many frames available - limit */
-      tnfr = (long)s->record.bufframes;
+      tnfr = (long)s->record.maxframes;
     }
     if (nfr > tnfr) {
       nfr = tnfr;
@@ -1146,8 +1147,19 @@ oss_stream_init(cubeb * context, cubeb_stream ** stream,
     else {
       s->play.bufframes = (bi.fragsize * bi.fragstotal) / s->play.frame_size;
     }
+    int lw;
 
-    int lw = s->play.frame_size;
+    /*
+     * Force 32 ms service intervals at most, or when recording is
+     * active, use the recording service intervals as a reference.
+     */
+    s->play.maxframes = (32 * output_stream_params->rate) / 1000;
+    if (s->record.fd != -1 || s->play.maxframes >= s->play.bufframes) {
+      lw = s->play.frame_size;        /* Feed data when possible. */
+      s->play.maxframes = s->play.bufframes;
+    } else {
+      lw = (s->play.bufframes - s->play.maxframes) * s->play.frame_size;
+    }
     if (ioctl(s->play.fd, SNDCTL_DSP_LOW_WATER, &lw))
       LOG("Audio device \"%s\" (play) could not set trigger threshold",
           s->play.name);
@@ -1166,6 +1178,7 @@ oss_stream_init(cubeb * context, cubeb_stream ** stream,
           (bi.fragsize * bi.fragstotal) / s->record.frame_size;
     }
 
+    s->record.maxframes = s->record.bufframes;
     int lw = s->record.frame_size;
     if (ioctl(s->record.fd, SNDCTL_DSP_LOW_WATER, &lw))
       LOG("Audio device \"%s\" (record) could not set trigger threshold",
