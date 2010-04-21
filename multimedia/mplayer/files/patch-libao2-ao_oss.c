--- libao2/ao_oss.c.orig	2009-05-12 21:58:57.000000000 -0500
+++ libao2/ao_oss.c	2009-07-23 19:58:44.870097203 -0500
@@ -453,6 +453,7 @@
   fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
 #endif
 
+  ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   oss_format = format2oss(ao_data.format);
   if(ao_data.format == AF_FORMAT_AC3)
     ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
@@ -464,7 +465,6 @@
       int c = ao_data.channels-1;
       ioctl (audio_fd, SNDCTL_DSP_STEREO, &c);
     }
-    ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   }
 }
 
