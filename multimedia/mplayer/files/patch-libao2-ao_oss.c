--- libao2/ao_oss.c.orig
+++ libao2/ao_oss.c
@@ -433,6 +433,7 @@
   fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
 #endif
 
+  ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   oss_format = format2oss(ao_data.format);
   ioctl (audio_fd, SNDCTL_DSP_SETFMT, &oss_format);
   if(ao_data.format != AF_FORMAT_AC3) {
@@ -442,7 +443,6 @@
       int c = ao_data.channels-1;
       ioctl (audio_fd, SNDCTL_DSP_STEREO, &c);
     }
-    ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   }
 }
 
