--- src/OSS/audio.c.original	2008-04-16 22:16:27.000000000 +0200
+++ src/OSS/audio.c	2008-04-16 22:16:50.000000000 +0200
@@ -497,7 +497,7 @@
             do_pause = FALSE;
             paused = TRUE;
 
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
         }
         else if (unpause && paused) {
             unpause = FALSE;
@@ -514,7 +514,7 @@
              * the driver to get fucked up by a reset
              */
 
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
             close(fd);
             fd = open(device_name, O_WRONLY);
             oss_set_audio_params();
@@ -527,7 +527,7 @@
 
     }
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     close(fd);
     g_free(buffer);
     return NULL;
@@ -540,7 +540,7 @@
     struct timeval tv;
     fd_set set;
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     frag = (NFRAGS << 16) | fragsize;
     ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &frag);
     /*
