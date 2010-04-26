--- src/OSS4/audio.c.orig	2010-04-26 16:11:51.000000000 +0200
+++ src/OSS4/audio.c	2010-04-26 16:11:43.000000000 +0200
@@ -204,26 +204,12 @@
     case FMT_U16_BE:
         format = AFMT_U16_BE;
         break;
-    case FMT_U16_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_U16_BE;
-#else
-        format = AFMT_U16_LE;
-#endif
-        break;
     case FMT_S16_LE:
         format = AFMT_S16_LE;
         break;
     case FMT_S16_BE:
         format = AFMT_S16_BE;
         break;
-    case FMT_S16_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_S16_BE;
-#else
-        format = AFMT_S16_LE;
-#endif
-        break;   
 #if 0  /* OSS currently doesn't support AFMT_U24_* */
     case FMT_U24_LE:
         format = AFMT_U24_LE;
@@ -231,13 +217,6 @@
     case FMT_U24_BE:
         format = AFMT_U24_BE;
         break;
-    case FMT_U24_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_U24_BE;
-#else
-        format = AFMT_U24_LE;
-#endif
-        break;
 #endif
     case FMT_S24_LE:
         format = AFMT_S24_LE;
@@ -245,13 +224,6 @@
     case FMT_S24_BE:
         format = AFMT_S24_BE;
         break;
-    case FMT_S24_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_S24_BE;
-#else
-        format = AFMT_S24_LE;
-#endif
-        break;
 #if 0  /* OSS currently doesn't support AFMT_U32_* */
     case FMT_U32_LE:
         format = AFMT_U32_LE;
@@ -259,13 +231,6 @@
     case FMT_U32_BE:
         format = AFMT_U32_BE;
         break;
-    case FMT_U32_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_U32_BE;
-#else
-        format = AFMT_U32_LE;
-#endif
-        break;
 #endif
     case FMT_S32_LE:
         format = AFMT_S32_LE;
@@ -273,13 +238,6 @@
     case FMT_S32_BE:
         format = AFMT_S32_BE;
         break;
-    case FMT_S32_NE:
-#if (G_BYTE_ORDER == G_BIG_ENDIAN)
-        format = AFMT_S32_BE;
-#else
-        format = AFMT_S32_LE;
-#endif
-        break;
     }
     return format;
 }
@@ -633,7 +591,7 @@
              * soundcard, but not yet played.  I don't
              * think this is worth fixing.
              */
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
         }
         else if (unpause && paused) {
             unpause = FALSE;
@@ -650,7 +608,7 @@
              * the driver to get fucked up by a reset
              */
 
-            ioctl(fd, SNDCTL_DSP_SYNC, 0);
+            ioctl(fd, SNDCTL_DSP_RESET, 0);
             close(fd);
             fd = open(device_name, O_WRONLY);
             oss_set_audio_params();
@@ -663,7 +621,7 @@
 
     }
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     oss_set_volume(start_vol_l, start_vol_r);
     close(fd);
     g_free(buffer);
@@ -677,7 +635,7 @@
     struct timeval tv;
     fd_set set;
 
-    ioctl(fd, SNDCTL_DSP_SYNC, 0);
+    ioctl(fd, SNDCTL_DSP_RESET, 0);
     frag = (NFRAGS << 16) | fragsize;
     ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &frag);
     /*
