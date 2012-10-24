--- libao2/ao_oss.c~	2012-05-10 23:45:22.000000000 -0500
+++ libao2/ao_oss.c	2012-05-11 00:03:17.820525648 -0500
@@ -460,6 +460,7 @@ static void reset(void){
   fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
 #endif
 
+  ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   oss_format = format2oss(ao_data.format);
   if(AF_FORMAT_IS_AC3(ao_data.format))
     ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
@@ -471,7 +472,6 @@ static void reset(void){
       int c = ao_data.channels-1;
       ioctl (audio_fd, SNDCTL_DSP_STEREO, &c);
     }
-    ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   }
 }
 
