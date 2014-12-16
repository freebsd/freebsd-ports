--- modules/audio_output/oss.c.orig	2014-02-27 14:31:53.000000000 +0100
+++ modules/audio_output/oss.c	2014-09-21 13:19:37.000000000 +0200
@@ -37,6 +37,7 @@
 #else
 # include <sys/soundcard.h>
 #endif
+#include <errno.h>
 
 #ifndef SNDCTL_DSP_HALT
 # define SNDCTL_DSP_HALT SNDCTL_DSP_RESET
@@ -209,6 +210,22 @@
     }
     aout_FormatPrepare (fmt);
 
+    /* Select timing */
+    unsigned bytes;
+    char buf[1024];
+
+    if (spdif)
+        bytes = AOUT_SPDIF_SIZE;
+    else
+        bytes = fmt->i_rate / (CLOCK_FREQ / AOUT_MIN_PREPARE_TIME)
+                * fmt->i_bytes_per_frame;
+
+    int frag = (AOUT_MAX_ADVANCE_TIME / AOUT_MIN_PREPARE_TIME) << 16
+             | (32 - clz32(bytes - 1));
+    if (ioctl (fd, SNDCTL_DSP_SETFRAGMENT, &frag) < 0)
+        msg_Err (aout, "cannot set 0x%08x fragment: %s", frag,
+                 strerror_r(errno, buf, sizeof(buf) - 1));
+
     sys->fd = fd;
     VolumeSync (aout);
     sys->starting = true;
@@ -230,8 +247,8 @@
         return -1;
     }
 
-    *pts = (delay * CLOCK_FREQ * sys->format.i_frame_length)
-                        / (sys->format.i_rate * sys->format.i_bytes_per_frame);
+    *pts = (delay * CLOCK_FREQ)
+	/ (sys->format.i_rate * sys->format.i_bytes_per_frame);
     return 0;
 }
 
