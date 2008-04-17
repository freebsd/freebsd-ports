--- src/OSS4/audio.c.original	2008-04-16 22:12:24.000000000 +0200
+++ src/OSS4/audio.c	2008-04-16 22:13:22.000000000 +0200
@@ -555,7 +555,7 @@
              * soundcard, but not yet played.  I don't
              * think this is worth fixing.
              */
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
         }
         else if (unpause && paused) {
             unpause = FALSE;
@@ -572,7 +572,7 @@
              * the driver to get fucked up by a reset
              */
 
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
             close(fd);
             fd = open(device_name, O_WRONLY);
             oss_set_audio_params();
@@ -585,7 +585,7 @@
 
     }
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     oss_set_volume(start_vol_l, start_vol_r);
     close(fd);
     g_free(buffer);
@@ -599,7 +599,7 @@
     struct timeval tv;
     fd_set set;
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     frag = (NFRAGS << 16) | fragsize;
     ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &frag);
     /*
