--- src/xdvshow-shm.c.orig	Wed May 15 21:14:42 2002
+++ src/xdvshow-shm.c	Mon Aug 18 19:53:49 2003
@@ -213,6 +213,7 @@
       _xdvshow_shm.shm_frame->frame_buf->lock = DVFRAME_COPYING;
       break;
     }
+    usleep(1);
   }
 
    *dvframe = _xdvshow_shm.shm_frame->frame_buf->data;
@@ -238,6 +239,7 @@
       _xdvshow_shm.audio_shm_frame->frame_buf->lock = DVFRAME_COPYING;
       break;
     }
+    usleep(1);
   }
 
   *audioframe = _xdvshow_shm.audio_shm_frame->frame_buf->data;
